/* Embroidermodder 2.
 * ------------------------------------------------------------
 * Copyright 2021-2022 The Embroidermodder Team
 * Embroidermodder 2 is Open Source Software.
 * See LICENCE for licensing terms.
 * ------------------------------------------------------------
 * This file is for the functions, not the data, of Embroidermodder 2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <sys/stat.h>
#include <math.h>

#if defined(__unix__) || defined(__linux__)
#include <pwd.h>
#include <unistd.h>
#else
#include <windows.h>
#endif

#include "GL/freeglut.h"

#include "embroidermodder.h"

/* DATA SECTION */
texture_t tex[N_TEXTURES];
GLuint texture[N_TEXTURES];
char *folders[] = {
    "",
    "commands",
    "help",
    "icons",
    "images",
    "samples",
    "translations"
};

settings_wrapper settings, preview, dialog, accept_;

int interaction_mode = 0;
int run = 1;
float mouse[2];
int mouse_x = 0;
int mouse_y = 0;

void build_right_click_menu(void);
void build_toolbar_menu(void);
void build_menubar_menu(void);

/* FUNCTIONS SECTION */

int main(int argc, char *argv[])
{
    int window, rightclick_menu, menu_ids[10], i, j;
    puts("SDL2 version of Embroidermodder");
    
    settings.window_width = 640;
    settings.window_height = 480;
    settings.window_x = 100;
    settings.window_y = 100;
    settings.window_aspect = 640.0/480.0;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(settings.window_width, settings.window_height);
    glutInitWindowPosition(settings.window_x, settings.window_y);
    window = glutCreateWindow("Embroidermodder 2");
    glClearColor (0.5, 0.5, 0.5, 0.0);

    build_right_click_menu();
    build_toolbar_menu();
    build_menubar_menu();

    glutDisplayFunc(display);
    glutKeyboardFunc(key_handler);
    glutMainLoop();
    return 0;
}

void build_right_click_menu(void)
{
    int i, j, menu_ids[10];
    for (j=0; j<n_menus; j++) {
        menu_ids[j] = glutCreateMenu(menu);
        for (i=0; menus[j][i] > -2; i++) {
            int act = menus[j][i];
            if (act>=0) {
                glutAddMenuEntry(action_list[act].menu_name, action_list[act].id);
            }
        }
    }
    rightclick_menu = glutCreateMenu(menu);
    for (j=0; j<n_menus; j++) {
        glutAddSubMenu(menu_label[j], menu_ids[j]);
    }
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void build_toolbar_menu(void)
{

}

void build_menubar_menu(void)
{
    int i;
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(N_TEXTURES, texture);
    for (i=0; i<N_TEXTURES; i++) {
        generate_texture(i);
    }
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);
}

double sgn(double x)
{
    if (x > 0.0) return 1.0;
    else if(x < 0.0) return -1.0;
    else return 0.0;
}

double theta(double x)
{
    if (x < 0.0) return 0.0;
    else return 1.0;
}

EmbVector unit_vector(float angle)
{
    EmbVector u;
    u.x = cos(angle);
    u.y = sin(angle);
    return u;
}

EmbVector rotate_vector(EmbVector a, float angle)
{
    EmbVector rot;
    EmbVector u = unit_vector(angle);
    rot.x = a.x*u.x - a.y*u.y;
    rot.y = a.x*u.y + a.y*u.x;
    return rot;
}

EmbVector scale_vector(EmbVector a, float scale)
{
    a.x *= scale;
    a.y *= scale;
    return a;
}

EmbVector scale_and_rotate(EmbVector a, float scale, float angle)
{
    a = scale_vector(a, scale);
    a = rotate_vector(a, angle);
    return a;
}


void app_dir(char *output, int folder)
{
#if defined(__unix__) || defined(__linux__)
    char *separator = "/";

    strcpy(output, getenv("HOME"));

    /* On MacOS we set a system "HOME" manually if it is not set. */
    if (!output) {
        struct passwd* pwd = getpwuid(getuid());
        if (pwd) {
            output = pwd->pw_dir;
        }
        else {
            printf("ERROR: failed to set HOME.");
        }
    }

#else
    char *separator = "\\";

    strcpy(output, getenv("HOMEDRIVE"));
    strcat(output, getenv("HOMEPATH"));
#endif

    strcat(output, separator);
    strcat(output, ".embroidermodder2");
    strcat(output, separator);

    if (folder >= 0 && folder < nFolders) {
        strcat(output, folders[folder]);
        strcat(output, separator);
    }
}

/* UTILITY FUNCTIONS FOR ALL SYSTEMS */
void debug_message(const char *format, ...)
{
    if (DEBUG) {
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        printf("\n");
        va_end(args);
    }
}

int file_exists(char *fname)
{
    struct stat stats;
    return !stat(fname, &stats);
}

void render_quadlist(quad *qlist)
{
    int i;
    glViewport(0, 0, settings.window_width, settings.window_height);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    for (i=0; qlist[i].flag; i++) {
        glColor3f(qlist[i].red, qlist[i].green, qlist[i].blue);
        glBegin(GL_QUADS);
        glVertex2f(qlist[i].left, qlist[i].top);
        glVertex2f(qlist[i].left, qlist[i].bottom);
        glVertex2f(qlist[i].right, qlist[i].bottom);
        glVertex2f(qlist[i].right, qlist[i].top);
        glEnd();
    }
}

void menu(int key)
{
    switch (key) {
    default:
        break;
    }
}

void display()
{
    /* render_quadlist(quad_list1); */
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (i=0; i<N_TEXTURES; i++) {
        glBindTexture(GL_TEXTURE_2D, texture[i]);
        glBegin(GL_QUADS);
        glTexCoord2f(tex[i].position[0], tex[i].position[1]);
        glVertex2f(tex[i].corners[0], tex[i].corners[1]);
        glTexCoord2f(tex[i].position[2], tex[i].position[3]);
        glVertex2f(tex[i].corners[2], tex[i].corners[3]);
        glTexCoord2f(tex[i].position[4], tex[i].position[5]);
        glVertex2f(tex[i].corners[4], tex[i].corners[5]);
        glTexCoord2f(tex[i].position[6], tex[i].position[7]);
        glVertex2f(tex[i].corners[6], tex[i].corners[7]);
        glEnd();
    }
    glutSwapBuffers();
}

void key_handler(int key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
    default:
        break;
    }
}

#include "icons/new.c"

void generate_texture(int i)
{
    int icon_size = 16;
    tex[i].width = 128;
    tex[i].height = 128;
    float h = icon_size/(0.5*settings.window_height);
    float w = icon_size/(0.5*settings.window_width); 
    tex[i].corners[0] = -1.0+w*(i-1);
    tex[i].corners[1] = 1.0;
    tex[i].corners[2] = -1.0+w*(i-1);
    tex[i].corners[3] = 1.0-h;
    tex[i].corners[4] = -1.0+w*i;
    tex[i].corners[5] = 1.0-h;
    tex[i].corners[6] = -1.0+w*i;
    tex[i].corners[7] = 1.0;
    tex[i].position[0] = 0.0;
    tex[i].position[1] = 0.0;
    tex[i].position[2] = 0.0;
    tex[i].position[3] = 1.0;
    tex[i].position[4] = 1.0;
    tex[i].position[5] = 1.0;
    tex[i].position[6] = 1.0;
    tex[i].position[7] = 0.0;
    glBindTexture(GL_TEXTURE_2D, texture[i]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, tex[i].width, tex[i].height, 0,
        GL_RGB, GL_UNSIGNED_BYTE, icon_new);
}


