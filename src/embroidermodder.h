#ifndef EMBROIDERMODDER_H
#define EMBROIDERMODDER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "embroidery.h"

/*
 * Defines
 * -------
 */

#define DEBUG                1
#define MAX_STRING_LENGTH  500

#define TOOLBAR_FILE         0
#define TOOLBAR_EDIT         1
#define TOOLBAR_VIEW         2
#define TOOLBAR_ZOOM         3
#define TOOLBAR_PAN          4
#define TOOLBAR_ICON         5
#define TOOLBAR_HELP         6
#define TOOLBAR_LAYER        7
#define TOOLBAR_TEXT         8
#define TOOLBAR_PROPERTIES   9

#define MENU_FILE            0
#define MENU_EDIT            1
#define MENU_VIEW            2
#define MENU_SETTINGS        3
#define MENU_WINDOW          4
#define MENU_HELP            5
#define MENU_RECENT          6
#define MENU_ZOOM            7
#define MENU_PAN             8

#define SYMBOL_zero          0
#define SYMBOL_one           1
#define SYMBOL_two           2
#define SYMBOL_three         3
#define SYMBOL_four          4
#define SYMBOL_five          5
#define SYMBOL_six           6
#define SYMBOL_seven         7
#define SYMBOL_eight         8
#define SYMBOL_nine          9
#define SYMBOL_minus        10
#define SYMBOL_apostrophe   11
#define SYMBOL_quote        12

/* Keys */
/* ---- */
/* value type - int: See OBJ_TYPE_VALUES */
#define OBJ_TYPE    0
/* value type - str: See OBJ_NAME_VALUES */
#define OBJ_NAME    1
/* value type - str: "USER", "DEFINED", "STRINGS", etc... */
#define OBJ_LAYER   2
/* value type - int: 0-255
  TODO: Use color chart in formats/format-dxf.h for this */
#define OBJ_COLOR   3
//value type - int: See OBJ_LTYPE_VALUES
#define OBJ_LTYPE   4
 //value type - int: 0-27
#define OBJ_LWT 5
/* value type - int: See OBJ_RUBBER_VALUES */
#define OBJ_RUBBER  6

/* Values */
/* ------ */
/* NOTE: Allow this enum to evaluate false */
#define OBJ_TYPE_NULL          0
/* NOTE: Values >= 65536 ensure compatibility with qgraphicsitem_cast() */
#define OBJ_TYPE_BASE          100000
#define OBJ_TYPE_ARC           100001
#define OBJ_TYPE_BLOCK         100002
#define OBJ_TYPE_CIRCLE        100003
#define OBJ_TYPE_DIMALIGNED    100004
#define OBJ_TYPE_DIMANGULAR    100005
#define OBJ_TYPE_DIMARCLENGTH  100006
#define OBJ_TYPE_DIMDIAMETER   100007
#define OBJ_TYPE_DIMLEADER 100008
#define OBJ_TYPE_DIMLINEAR 100009
#define OBJ_TYPE_DIMORDINATE   100010
#define OBJ_TYPE_DIMRADIUS 100011
#define OBJ_TYPE_ELLIPSE   100012
#define OBJ_TYPE_ELLIPSEARC    100013
#define OBJ_TYPE_RUBBER    100014
#define OBJ_TYPE_GRID  100015
#define OBJ_TYPE_HATCH 100016
#define OBJ_TYPE_IMAGE 100017
#define OBJ_TYPE_INFINITELINE  100018
#define OBJ_TYPE_LINE  100019
#define OBJ_TYPE_PATH  100020
#define OBJ_TYPE_POINT         100021
#define OBJ_TYPE_POLYGON       100022
#define OBJ_TYPE_POLYLINE      100023
#define OBJ_TYPE_RAY           100024
#define OBJ_TYPE_RECTANGLE     100025
#define OBJ_TYPE_SLOT          100026
#define OBJ_TYPE_SPLINE        100027
#define OBJ_TYPE_TEXTMULTI     100028
#define OBJ_TYPE_TEXTSINGLE    100029
#define OBJ_TYPE_UNKNOWN    100030


/* CAD Linetypes */
#define OBJ_LTYPE_CONT   0
#define OBJ_LTYPE_CENTER 1
#define OBJ_LTYPE_DOT    2
#define OBJ_LTYPE_HIDDEN 3
#define OBJ_LTYPE_PHANTOM    4
#define OBJ_LTYPE_ZIGZAG 5
/* Embroidery Stitchtypes */
/* __________ */
#define OBJ_LTYPE_RUNNING    6
/* vvvvvvvvvv */
#define OBJ_LTYPE_SATIN  7
/* >>>>>>>>>> */
#define OBJ_LTYPE_FISHBONE   8

/* OBJ_LWT_VALUES
 * --------------
 */
#define OBJ_LWT_BYLAYER (-2)
#define OBJ_LWT_BYBLOCK (-1)
#define OBJ_LWT_DEFAULT   0
#define OBJ_LWT_01    1
#define OBJ_LWT_02    2 
#define OBJ_LWT_03    3 
#define OBJ_LWT_04    4 
#define OBJ_LWT_05    5 
#define OBJ_LWT_06    6 
#define OBJ_LWT_07    7 
#define OBJ_LWT_08    8 
#define OBJ_LWT_09    9 
#define OBJ_LWT_10   10 
#define OBJ_LWT_11   11 
#define OBJ_LWT_12   12 
#define OBJ_LWT_13   13 
#define OBJ_LWT_14   14 
#define OBJ_LWT_15   15 
#define OBJ_LWT_16   16 
#define OBJ_LWT_17   17 
#define OBJ_LWT_18   18 
#define OBJ_LWT_19   19 
#define OBJ_LWT_20   20 
#define OBJ_LWT_21   21 
#define OBJ_LWT_22   22 
#define OBJ_LWT_23   23 
#define OBJ_LWT_24   24

/* OBJ_SNAP_VALUES */
/* --------------- */
/* NOTE: Allow this enum to evaluate false */
#define OBJ_SNAP_NULL  0
#define OBJ_SNAP_ENDPOINT  1
#define OBJ_SNAP_MIDPOINT  2
#define OBJ_SNAP_CENTER    3
#define OBJ_SNAP_NODE  4
#define OBJ_SNAP_QUADRANT  5
#define OBJ_SNAP_INTERSECTION  6
#define OBJ_SNAP_EXTENSION 7
#define OBJ_SNAP_INSERTION 8
#define OBJ_SNAP_PERPENDICULAR 9
#define OBJ_SNAP_TANGENT  10
#define OBJ_SNAP_NEAREST  11
#define OBJ_SNAP_APPINTERSECTION  12
#define OBJ_SNAP_PARALLEL 13


/* OBJ_RUBBER_VALUES
 * -----------------
 * NOTE: Allow this enum to evaluate false */
#define OBJ_RUBBER_OFF    0
/* NOTE: Allow this enum to evaluate true */
#define OBJ_RUBBER_ON 1
#define OBJ_RUBBER_CIRCLE_1P_RAD  2
#define OBJ_RUBBER_CIRCLE_1P_DIA  3
#define OBJ_RUBBER_CIRCLE_2P  4
#define OBJ_RUBBER_CIRCLE_3P  5
#define OBJ_RUBBER_CIRCLE_TTR 6
#define OBJ_RUBBER_CIRCLE_TTT 7
#define OBJ_RUBBER_DIMLEADER_LINE 8
#define OBJ_RUBBER_ELLIPSE_LINE   9
#define OBJ_RUBBER_ELLIPSE_MAJORDIAMETER_MINORRADIUS 10
#define OBJ_RUBBER_ELLIPSE_MAJORRADIUS_MINORRADIUS  11
#define OBJ_RUBBER_ELLIPSE_ROTATION  12
#define OBJ_RUBBER_GRIP  13
#define OBJ_RUBBER_LINE  14
#define OBJ_RUBBER_POLYGON   15
#define OBJ_RUBBER_POLYGON_INSCRIBE  16
#define OBJ_RUBBER_POLYGON_CIRCUMSCRIBE 17
#define OBJ_RUBBER_POLYLINE  18
#define OBJ_RUBBER_IMAGE 19
#define OBJ_RUBBER_RECTANGLE 20
#define OBJ_RUBBER_TEXTSINGLE    21

/* SPARE_RUBBER_VALUES
 * -------------------
 * NOTE: Allow this enum to evaluate false */
#define SPARE_RUBBER_OFF    0
#define SPARE_RUBBER_PATH   1
#define SPARE_RUBBER_POLYGON    2
#define SPARE_RUBBER_POLYLINE   3


/* PREVIEW_CLONE_VALUES
 * --------------------
 * NOTE: Allow this enum to evaluate false */
#define PREVIEW_CLONE_NULL  0
#define PREVIEW_CLONE_SELECTED  1
#define PREVIEW_CLONE_RUBBER    2


/* PREVIEW_MODE_VALUES
 * -------------------
 * NOTE: Allow this enum to evaluate false */
#define PREVIEW_MODE_NULL   0
#define PREVIEW_MODE_MOVE   1
#define PREVIEW_MODE_ROTATE 2
#define PREVIEW_MODE_SCALE  3


/* COMMAND ACTIONS */
/* --------------- */
#define ACTION_null   0
#define ACTION_donothing  1
#define ACTION_new    2
#define ACTION_open   3
#define ACTION_save   4
#define ACTION_saveas 5
#define ACTION_print  6
#define ACTION_designdetails  7
#define ACTION_exit   8
#define ACTION_cut    9
#define ACTION_copy   10
#define ACTION_paste  11
#define ACTION_undo   12
#define ACTION_redo   13
/* Window Menu */
#define ACTION_windowclose    14
#define ACTION_windowcloseall 15
#define ACTION_windowcascade  16
#define ACTION_windowtile 17
#define ACTION_windownext 18
#define ACTION_windowprevious 19
/* Help Menu */
#define ACTION_help   20
#define ACTION_changelog  21
#define ACTION_tipoftheday    22
#define ACTION_about  23
#define ACTION_whatsthis  24
/* Icons */
#define ACTION_icon16 25
#define ACTION_icon24 26
#define ACTION_icon32 27
#define ACTION_icon48 28
#define ACTION_icon64 29
#define ACTION_icon128    30
#define ACTION_settingsdialog 31
/* Layer ToolBar */
#define ACTION_makelayercurrent 32
#define ACTION_layers   33
#define ACTION_layerselector    34
#define ACTION_layerprevious    35
#define ACTION_colorselector    36
#define ACTION_linetypeselector 37
#define ACTION_lineweightselector 38
#define ACTION_hidealllayers    39
#define ACTION_showalllayers    40
#define ACTION_freezealllayers  41
#define ACTION_thawalllayers    42
#define ACTION_lockalllayers    43
#define ACTION_unlockalllayers  44
/* Text ToolBar */
#define ACTION_textbold 45
#define ACTION_textitalic   46
#define ACTION_textunderline    47
#define ACTION_textstrikeout    48
#define ACTION_textoverline 49
/* Zoom ToolBar */
#define ACTION_zoomrealtime 50
#define ACTION_zoomprevious 51
#define ACTION_zoomwindow   52
#define ACTION_zoomdynamic  53
#define ACTION_zoomscale    54
#define ACTION_zoomcenter   55
#define ACTION_zoomin   56
#define ACTION_zoomout  57
#define ACTION_zoomselected 58
#define ACTION_zoomall  59
#define ACTION_zoomextents  60
/* Pan SubMenu */
#define ACTION_panrealtime  61
#define ACTION_panpoint 62
#define ACTION_panleft  63
#define ACTION_panright 64
#define ACTION_panup    65
#define ACTION_pandown  66
/* View */
#define ACTION_day  67
#define ACTION_night    68

/* Just added */
#define ACTION_delete   69

/*
TODO: ACTION_spellcheck 
TODO: ACTION_quickselect 
*/

#define circle_mode_1P_RAD   0
#define circle_mode_1P_DIA   1
#define circle_mode_2P       2
#define circle_mode_3P       3
#define circle_mode_TTR      4

#define app_folder  0
#define commands_folder 1
#define help_folder 2
#define icons_folder    3
#define images_folder   4
#define samples_folder  5
#define translations_folder 6
#define nFolders    7

#define PATHS_MOVETO    0
#define PATHS_LINETO    1
#define PATHS_ARCTO     2
#define PATHS_ARCMOVETO 3
#define PATHS_ELLIPSE   4
#define PATHS_END       5

#define N_TEXTURES      10

/*
 * TYPEDEFS
 * --------
 */

typedef struct Path_Symbol__ {
    int type;
    float values[6];
} path_symbol;

typedef struct Action_hash_data {
    int id;
    char **icon;
    char abbreviation[20];
    char menu_name[30];
    char description[100];
    char shortcut[20];
    void (*function)(void);
} action_hash_data;

typedef struct Action_call_ {
    int id;
    float float_args[10];
    int int_args[10];
    char str_args[4][MAX_STRING_LENGTH];
    int args_set;
} action_call;

typedef struct circle_args_ {
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    float rad;
    float dia;
    float cx;
    float cy;
    int mode;
} circle_args;

typedef struct Quad {
    int flag;
    float left;
    float right;
    float top;
    float bottom;
    float red;
    float green;
    float blue;
} quad;

typedef struct Texture_t {
    float position[8];
    float corners[8];
    int width;
    int height;
} texture_t;

typedef struct Settings_wrapper {
    int window_width;
    int window_height;
    float window_aspect;
    int window_x;
    int window_y;
    int general_icon_size;
    int general_mdi_bg_use_logo;
    int general_mdi_bg_use_texture;
    int general_mdi_bg_use_color;
    int qsnap_endpoint;
    int qsnap_midpoint;
    int qsnap_center;
    int qsnap_node;
    int qsnap_quadrant;
    int qsnap_intersection;
    int qsnap_extension;
    int qsnap_insertion;
    int qsnap_perpendicular;
    int qsnap_tangent;
    int qsnap_nearest;
    int qsnap_apparent;
    int qsnap_parallel;
    int grid_center_on_origin;
    float grid_center_x;
    float grid_center_y;
    float grid_size_x;
    float grid_size_y;
    float grid_spacing_x;
    float grid_spacing_y;
    float grid_size_radius;
    float grid_spacing_radius;
    float grid_spacing_angle;
    int ruler_show_on_load;
    int ruler_metric;
    int general_tip_of_the_day;
    int general_system_help_browser;
    int general_check_for_updates;
    int display_use_opengl;
    int display_renderhint_aa;
    int display_renderhint_text_aa;
    int display_renderhint_smooth_pix;
    int display_renderhint_high_aa;
    int display_renderhint_noncosmetic;
    int display_show_scrollbars;
    int display_scrollbar_widget_num;
    float display_zoomscale_in;
    float display_zoomscale_out;
    unsigned char display_selectbox_alpha;
    unsigned char display_crosshair_percent;
    int opensave_open_thumbnail;
    int opensave_save_thumbnail;
    unsigned char opensave_recent_max_files;
    unsigned char opensave_trim_dst_num_jumps;
    int printing_use_last_device;
    int printing_disable_bg;
    int grid_show_on_load;
    int grid_show_origin;
    int grid_color_match_crosshair;
    int grid_load_from_file;
    unsigned char ruler_pixel_size;
    int qsnap_enabled;
    unsigned char qsnap_locator_size;
    unsigned char qsnap_aperture_size;
    int lwt_show_lwt;
    int lwt_real_render;
    float lwt_default_lwt;
    int selection_mode_pickfirst;
    int selection_mode_pickadd;
    int selection_mode_pickdrag;
    unsigned char selection_grip_size;
    unsigned char selection_pickbox_size;
    float text_size;
    float text_angle;
    int text_style_bold;
    int text_style_italic;
    int text_style_underline;
    int text_style_overline;
    int text_style_strikeout;

    quad quad_list1[20];
    quad quad_list2[20];

    int rulerPixelSize;
    int gripSize;
    int pickBoxSize;
    int crosshairSize;

    int shiftKeyPressedState;

    int grippingActive;
    int rapidMoveActive;
    int previewActive;
    int pastingActive;
    int movingActive;
    int selectingActive;
    int zoomWindowActive;
    int panningRealTimeActive;
    int panningPointActive;
    int panningActive;
    int qSnapActive;
    int qSnapToggle;

    int rulerMetric;

    char general_language[MAX_STRING_LENGTH];
    char general_icon_theme[MAX_STRING_LENGTH];
    char general_mdi_bg_logo[MAX_STRING_LENGTH];
    char general_mdi_bg_texture[MAX_STRING_LENGTH];
    unsigned int general_mdi_bg_color;
    unsigned short general_current_tip;
    unsigned int display_crosshair_color;
    unsigned int display_bg_color;
    unsigned int display_selectbox_left_color;
    unsigned int display_selectbox_left_fill;
    unsigned int display_selectbox_right_color;
    unsigned int display_selectbox_right_fill;
    char display_units[MAX_STRING_LENGTH];
    char opensave_open_format[MAX_STRING_LENGTH];
    char opensave_save_format[MAX_STRING_LENGTH];
    char opensave_recent_directory[MAX_STRING_LENGTH];
    char printing_default_device[MAX_STRING_LENGTH];
    unsigned int grid_color;
    unsigned int ruler_color;
    unsigned int qsnap_locator_color;
    char grid_type[MAX_STRING_LENGTH];
    unsigned int selection_coolgrip_color;
    unsigned int selection_hotgrip_color;
    char text_font[MAX_STRING_LENGTH];
} settings_wrapper;

/* C Data for embroidermodder
 * --------------------------
 */

extern path_symbol *symbol_list[20];
extern int n_toolbars, n_actions, n_menus;
extern int *toolbars[];
extern int *menus[];
extern char *toolbar_label[];
extern action_call undo_history[1000];
extern action_call action;
extern int undo_history_length;
extern int undo_history_position;
extern action_hash_data action_list[];
extern const char *actions_strings[];
extern char *menu_label[];
extern char *obj_names[];
extern char *icon_3dviews[];
extern char *icon_about[];
extern char *icon_aligneddimension[];
extern char *icon_aligntextangle[];
extern char *icon_aligntextcenter[];
extern char *icon_aligntexthome[];
extern char *icon_aligntextleft[];
extern char *icon_aligntextright[];
extern char *icon_aligntext[];
extern char *icon_angulardimension[];
extern char *icon_app[];
extern char *icon_arc3points[];
extern char *icon_arccenterstartangle[];
extern char *icon_arccenterstartend[];
extern char *icon_arccenterstartlength[];
extern char *icon_arccontinue[];
extern char *icon_arcstartcenterangle[];
extern char *icon_arcstartcenterend[];
extern char *icon_arcstartcenterlength[];
extern char *icon_arcstartendangle[];
extern char *icon_arcstartenddirection[];
extern char *icon_arcstartendradius[];
extern char *icon_arc[];
extern char *icon_area[];
extern char *icon_array[];
extern char *icon_backview[];
extern char *icon_baselinedimension[];
extern char *icon_bean[];
extern char *icon_blank[];
extern char *icon_bottomview[];
extern char *icon_boundary[];
extern char *icon_break2points[];
extern char *icon_breakatpoint[];
extern char *icon_browser[];
extern char *icon_camera[];
extern char *icon_centermark[];
extern char *icon_chamfer[];
extern char *icon_changelog[];
extern char *icon_check[];
extern char *icon_circle2points[];
extern char *icon_circle3points[];
extern char *icon_circlecenterdiameter[];
extern char *icon_circlecenterradius[];
extern char *icon_circletantanradius[];
extern char *icon_circletantantan[];
extern char *icon_circle[];
extern char *icon_cloud_2[];
extern char *icon_cloud[];
extern char *icon_colorblue[];
extern char *icon_colorbyblock[];
extern char *icon_colorbylayer[];
extern char *icon_colorcyan[];
extern char *icon_colorgreen[];
extern char *icon_colormagenta[];
extern char *icon_colorother[];
extern char *icon_colorred[];
extern char *icon_colorselector[];
extern char *icon_colorwhite[];
extern char *icon_coloryellow[];
extern char *icon_constructionline[];
extern char *icon_continuedimension[];
extern char *icon_copyobject[];
extern char *icon_copy[];
extern char *icon_customizekeyboard[];
extern char *icon_customizemenus[];
extern char *icon_customizetoolbars[];
extern char *icon_customize[];
extern char *icon_cut[];
extern char *icon_date[];
extern char *icon_day[];
extern char *icon_designdetails[];
extern char *icon_diameterdimension[];
extern char *icon_dimensionedit[];
extern char *icon_dimensionstyle[];
extern char *icon_dimensiontextedit[];
extern char *icon_dimensionupdate[];
extern char *icon_distance[];
extern char *icon_dolphin[];
extern char *icon_donothing[];
extern char *icon_donut_2[];
extern char *icon_donut[];
extern char *icon_drawing2[];
extern char *icon_drawing[];
extern char *icon_ellipsearc[];
extern char *icon_ellipseaxisend[];
extern char *icon_ellipsecenter[];
extern char *icon_ellipse[];
extern char *icon_erase[];
extern char *icon_escape[];
extern char *icon_exit[];
extern char *icon_explode[];
extern char *icon_extend[];
extern char *icon_fillet[];
extern char *icon_findandreplace[];
extern char *icon_freezealllayers[];
extern char *icon_frontview[];
extern char *icon_gridsettings[];
extern char *icon_gridsnapsettings[];
extern char *icon_hatch[];
extern char *icon_heart_2[];
extern char *icon_heart[];
extern char *icon_help_2[];
extern char *icon_help[];
extern char *icon_hex[];
extern char *icon_hidealllayers[];
extern char *icon_histogram[];
extern char *icon_icon128[];
extern char *icon_icon16[];
extern char *icon_icon24[];
extern char *icon_icon32[];
extern char *icon_icon48[];
extern char *icon_icon64[];
extern char *icon_inquiry[];
extern char *icon_insertblock[];
extern char *icon_join[];
extern char *icon_justifytext[];
extern char *icon_layerprevious[];
extern char *icon_layerselector[];
extern char *icon_layers[];
extern char *icon_layertranslate[];
extern char *icon_leftview[];
extern char *icon_lengthen[];
extern char *icon_lineardimension[];
extern char *icon_linetypebyblock[];
extern char *icon_linetypebylayer[];
extern char *icon_linetypecenter[];
extern char *icon_linetypecontinuous[];
extern char *icon_linetypehidden[];
extern char *icon_linetypeother[];
extern char *icon_linetypeselector[];
extern char *icon_lineweight01[];
extern char *icon_lineweight02[];
extern char *icon_lineweight03[];
extern char *icon_lineweight04[];
extern char *icon_lineweight05[];
extern char *icon_lineweight06[];
extern char *icon_lineweight07[];
extern char *icon_lineweight08[];
extern char *icon_lineweight09[];
extern char *icon_lineweight10[];
extern char *icon_lineweight11[];
extern char *icon_lineweight12[];
extern char *icon_lineweight13[];
extern char *icon_lineweight14[];
extern char *icon_lineweight15[];
extern char *icon_lineweight16[];
extern char *icon_lineweight17[];
extern char *icon_lineweight18[];
extern char *icon_lineweight19[];
extern char *icon_lineweight20[];
extern char *icon_lineweight21[];
extern char *icon_lineweight22[];
extern char *icon_lineweight23[];
extern char *icon_lineweight24[];
extern char *icon_lineweightbyblock[];
extern char *icon_lineweightbylayer[];
extern char *icon_lineweightdefault[];
extern char *icon_lineweightselector[];
extern char *icon_lineweightsettings[];
extern char *icon_line[];
extern char *icon_list[];
extern char *icon_locatepoint[];
extern char *icon_locator_snaptoapparentintersection[];
extern char *icon_locator_snaptocenter[];
extern char *icon_locator_snaptoendpoint[];
extern char *icon_locator_snaptoextension[];
extern char *icon_locator_snaptoinsert[];
extern char *icon_locator_snaptointersection[];
extern char *icon_locator_snaptomidpoint[];
extern char *icon_locator_snaptonearest[];
extern char *icon_locator_snaptonode[];
extern char *icon_locator_snaptoparallel[];
extern char *icon_locator_snaptoperpendicular[];
extern char *icon_locator_snaptoquadrant[];
extern char *icon_locator_snaptotangent[];
extern char *icon_lockalllayers[];
extern char *icon_makeblock[];
extern char *icon_makelayercurrent[];
extern char *icon_mass[];
extern char *icon_mirror[];
extern char *icon_move[];
extern char *icon_multilinetext[];
extern char *icon_multiline[];
extern char *icon_namedviews[];
extern char *icon_neisometricview[];
extern char *icon__new[];
extern char *icon_night[];
extern char *icon_nopreview[];
extern char *icon_nwisometricview[];
extern char *icon_obliquedimensions[];
extern char *icon_offset[];
extern char *icon_open[];
extern char *icon_ordinatedimension[];
extern char *icon_orthosettings[];
extern char *icon_pandown[];
extern char *icon_panleft[];
extern char *icon_panpoint[];
extern char *icon_panrealtime[];
extern char *icon_panright[];
extern char *icon_panup[];
extern char *icon_pan[];
extern char *icon_paste[];
extern char *icon_path[];
extern char *icon_pickadd[];
extern char *icon_picknew[];
extern char *icon_plugin[];
extern char *icon_pointdivide[];
extern char *icon_pointmeasure[];
extern char *icon_pointmultiple[];
extern char *icon_pointsingle[];
extern char *icon_point[];
extern char *icon_polarsettings[];
extern char *icon_polygon[];
extern char *icon_polyline[];
extern char *icon_print[];
extern char *icon_pyscript[];
extern char *icon_qsnapsettings[];
extern char *icon_qtracksettings[];
extern char *icon_quickdimension[];
extern char *icon_quickleader[];
extern char *icon_quickselect[];
extern char *icon_radiusdimension[];
extern char *icon_ray[];
extern char *icon_rectangle[];
extern char *icon_redo[];
extern char *icon_region[];
extern char *icon_render[];
extern char *icon_rgb[];
extern char *icon_rightview[];
extern char *icon_rotate[];
extern char *icon_rulersettings[];
extern char *icon_sandbox[];
extern char *icon_satin[];
extern char *icon_saveas[];
extern char *icon_save[];
extern char *icon_scale[];
extern char *icon_seisometricview[];
extern char *icon_settingsdialog_2[];
extern char *icon_settingsdialog[];
extern char *icon_shade2dwireframe[];
extern char *icon_shade3dwireframe[];
extern char *icon_shadeflatedges[];
extern char *icon_shadeflat[];
extern char *icon_shadehidden[];
extern char *icon_shadesmoothedges[];
extern char *icon_shadesmooth[];
extern char *icon_shade[];
extern char *icon_showalllayers[];
extern char *icon_singlelinetext[];
extern char *icon_sketch_2[];
extern char *icon_sketch[];
extern char *icon_snapfrom[];
extern char *icon_snaptoapparentintersection[];
extern char *icon_snaptocenter[];
extern char *icon_snaptoendpoint[];
extern char *icon_snaptoextension[];
extern char *icon_snaptoinsert[];
extern char *icon_snaptointersection[];
extern char *icon_snaptomidpoint[];
extern char *icon_snaptonearest[];
extern char *icon_snaptonode[];
extern char *icon_snaptonone[];
extern char *icon_snaptoparallel[];
extern char *icon_snaptoperpendicular[];
extern char *icon_snaptoquadrant[];
extern char *icon_snaptotangent[];
extern char *icon_snowflake_2[];
extern char *icon_snowflake[];
extern char *icon_solidbox[];
extern char *icon_solidcheck[];
extern char *icon_solidclean[];
extern char *icon_solidcoloredges[];
extern char *icon_solidcolorfaces[];
extern char *icon_solidcone[];
extern char *icon_solidcopyedges[];
extern char *icon_solidcopyfaces[];
extern char *icon_solidcylinder[];
extern char *icon_soliddeletefaces[];
extern char *icon_solidextrudefaces[];
extern char *icon_solidextrude[];
extern char *icon_solidimprint[];
extern char *icon_solidinterfere[];
extern char *icon_solidintersect[];
extern char *icon_solidmovefaces[];
extern char *icon_solidoffsetfaces[];
extern char *icon_solidrevolve[];
extern char *icon_solidrotatefaces[];
extern char *icon_solidsection[];
extern char *icon_solidsediting[];
extern char *icon_solidseparate[];
extern char *icon_solidsetupdrawing[];
extern char *icon_solidsetupprofile[];
extern char *icon_solidsetupview[];
extern char *icon_solidsetup[];
extern char *icon_solidshell[];
extern char *icon_solidslice[];
extern char *icon_solidsphere[];
extern char *icon_solidsubtract[];
extern char *icon_solids[];
extern char *icon_solidtaperfaces[];
extern char *icon_solidtorus[];
extern char *icon_solidunion[];
extern char *icon_solidwedge[];
extern char *icon_spline[];
extern char *icon_star[];
extern char *icon_stretch[];
extern char *icon_stub[];
extern char *icon_surface2dsolid[];
extern char *icon_surface3dface[];
extern char *icon_surface3dmesh[];
extern char *icon_surfacebox[];
extern char *icon_surfacecone[];
extern char *icon_surfacecylinder[];
extern char *icon_surfacedish[];
extern char *icon_surfacedome[];
extern char *icon_surfaceedgesurface[];
extern char *icon_surfaceedge[];
extern char *icon_surfacepyramid[];
extern char *icon_surfacerevolvedsurface[];
extern char *icon_surfaceruledsurface[];
extern char *icon_surfacesphere[];
extern char *icon_surfaces[];
extern char *icon_surfacetabulatedsurface[];
extern char *icon_surfacetorus[];
extern char *icon_surfacewedge[];
extern char *icon_swisometricview[];
extern char *icon_temptrackingpoint[];
extern char *icon_textbold[];
extern char *icon_textitalic[];
extern char *icon_textoverline[];
extern char *icon_textstrikeout[];
extern char *icon_textunderline[];
extern char *icon_text[];
extern char *icon_thawalllayers[];
extern char *icon_theme[];
extern char *icon_tipoftheday_2[];
extern char *icon_tipoftheday[];
extern char *icon_tolerance[];
extern char *icon_topview[];
extern char *icon_trim[];
extern char *icon_undo[];
extern char *icon_units[];
extern char *icon_unlockalllayers[];
extern char *icon_view[];
extern char *icon_whatsthis[];
extern char *icon_wideflange[];
extern char *icon_windowcascade[];
extern char *icon_windowcloseall[];
extern char *icon_windowclose[];
extern char *icon_windownext[];
extern char *icon_windowprevious[];
extern char *icon_windowtile[];
extern char *icon_world[];
extern char *icon_zoomall[];
extern char *icon_zoomcenter[];
extern char *icon_zoomdynamic[];
extern char *icon_zoomextents[];
extern char *icon_zoomin[];
extern char *icon_zoomout[];
extern char *icon_zoomprevious[];
extern char *icon_zoomrealtime[];
extern char *icon_zoomscale[];
extern char *icon_zoomselected[];
extern char *icon_zoomwindow[];
extern char *icon_zoom[];

/* C functions for embroidermodder
 * -------------------------------
 */

void debug_message(const char *format, ...);
void app_dir(char *string, int folder);
int file_exists(char *fname);
int parseJSON(char *fname);
int main_tex_example(int, char*argv[]);
double radians(double);
double degrees(double);
double sgn(double x);
double theta(double x);
void key_handler(int c, int x, int y);
void render_quadlist(quad *qlist);
void menu(int key);
void display(void);

/* Layer Toolbar */
void makeLayerActive(void);
void layerManager(void);
void layerPrevious(void);

/* Zoom Toolbar */
void zoomRealtime(void);
void zoomPrevious(void);
void zoomWindow(void);
void zoomDynamic(void);
void zoomScale(void);
void zoomCenter(void);
void zoomIn(void);
void zoomOut(void);
void zoomSelected(void);
void zoomAll();
void zoomExtents();

/* Pan SubMenu */
void panrealtime();
void panpoint();
void panLeft();
void panRight();
void panUp();
void panDown();

void dayVision(void);
void nightVision(void);

void main_undo(void);
void main_redo(void);

void doNothing(void);

EmbVector unit_vector(float angle);
EmbVector rotate_vector(EmbVector a, float angle);
EmbVector scale_vector(EmbVector a, float scale);
EmbVector scale_and_rotate(EmbVector a, float scale, float angle);

void texture_from_xpm(char *xpm_image[], char *texture);

/*
 * C++ Specific code
 * -----------------
 */
 #if 0
#ifdef __cplusplus
}

#include <QApplication>
#include <QCheckBox>
#include <QCloseEvent>
#include <QColorDialog>
#include <QComboBox>
#include <QDateTime>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDockWidget>
#include <QFileDialog>
#include <QFileOpenEvent>
#include <QFontComboBox>
#include <QFormLayout>
#include <QGraphicsItem>
#include <QGraphicsPathItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QLibraryInfo>
#include <QLineEdit>
#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QMetaObject>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>
#include <QRadioButton>
#include <QRandomGenerator>
#include <QScreen>
#include <QScrollBar>
#include <QSettings>
#include <QSignalMapper>
#include <QSortFilterProxyModel>
#include <QSpinBox>
#include <QStandardItemModel>
#include <QStandardPaths>
#include <QStatusBar>
#include <QStyleOption>
#include <QTextStream>
#include <QtGlobal>
#include <QToolBar>
#include <QToolButton>
#include <QTranslator>
#include <QTreeView>
#include <QVBoxLayout>
#include <QWhatsThis>
#include <QWizard>

class MainWindow;
class BaseObject;
class SelectBox;
class StatusBar;
class StatusBarButton;
class View;
class PropertyEditor;
class ImageWidget;

extern settings_wrapper settings, preview, dialog, accept;
extern QStringList opensave_recent_list_of_files;
extern MainWindow* _mainWin;
extern QString opensave_custom_filter;

void actuator(void);
void settings_actuator(void);

/* Class based code */
class LayerManager : public QDialog
{
    Q_OBJECT

public:
    LayerManager(MainWindow* mw, QWidget *parent = 0);
    ~LayerManager();

    void addLayer(const QString& name,
  const bool visible,
  const bool frozen,
  const float zValue,
  const unsigned int color,
  const QString& lineType,
  const QString& lineWeight,
  const bool print);

    QStandardItemModel*    layerModel;
    QSortFilterProxyModel* layerModelSorted;
    QTreeView* treeView;
};

// On Mac, if the user drops a file on the app's Dock icon, or uses Open As, then this is how the app actually opens the file.
class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int argc, char **argv);
    void setMainWin(MainWindow* mainWin) { _mainWin = mainWin; }
protected:
    virtual bool event(QEvent *e);
};

class ImageWidget : public QWidget
{
    Q_OBJECT

public:
    ImageWidget(const QString &filename, QWidget* parent = 0);
    ~ImageWidget();

    bool load(const QString &fileName);
    bool save(const QString &fileName);
    QImage img;

protected:
    void paintEvent(QPaintEvent* event);
};

class MdiWindow: public QMdiSubWindow
{
    Q_OBJECT

public:
    MdiWindow(const int theIndex, MainWindow* mw, QMdiArea* parent, Qt::WindowFlags wflags);
    ~MdiWindow();

    virtual QSize  sizeHint() const;
    QString    getCurrentFile()   { return curFile; }
    QString    getShortCurrentFile();
    View*  getView() { return gview; }
    QGraphicsScene*    getScene() { return gscene; }
    QString    getCurrentLayer() { return curLayer; }
    unsigned int   getCurrentColor() { return curColor; }
    QString    getCurrentLineType() { return curLineType; }
    QString    getCurrentLineWeight() { return curLineWeight; }
    void   setCurrentLayer(const QString& layer) { curLayer = layer; }
    void   setCurrentColor(const unsigned int& color) { curColor = color; }
    void   setCurrentLineType(const QString& lineType) { curLineType = lineType; }
    void   setCurrentLineWeight(const QString& lineWeight) { curLineWeight = lineWeight; }
    void   designDetails();
    bool   loadFile(const QString &fileName);
    bool   saveFile(const QString &fileName);
signals:
    void   sendCloseMdiWin(MdiWindow*);


private:
    MainWindow*    mainWin;
    QGraphicsScene*    gscene;
    QMdiArea*  mdiArea;
    View*  gview;
    int fileWasLoaded;

    /* QPrinter   printer; */

    QString curFile;
    void setCurrentFile(const QString& fileName);
    QString fileExtension(const QString& fileName);

    int myIndex;

    QString curLayer;
    unsigned int curColor;
    QString curLineType;
    QString curLineWeight;

public slots:
    void   closeEvent(QCloseEvent* e);
    void   onWindowActivated();

    void   currentLayerChanged(const QString& layer);
    void   currentColorChanged(const unsigned int& color);
    void   currentLinetypeChanged(const QString& type);
    void   currentLineweightChanged(const QString& weight);

    void   updateColorLinetypeLineweight();
    void   deletePressed();
    void   escapePressed();

    void   showViewScrollBars(bool val);
    void   setViewCrossHairColor(unsigned int color);
    void   setViewBackgroundColor(unsigned int color);
    void   setViewSelectBoxColors(unsigned int colorL, unsigned int fillL, unsigned int colorR, unsigned int fillR, int alpha);
    void   setViewGridColor(unsigned int color);
    void   setViewRulerColor(unsigned int color);

    void   print();
    void   saveBMC();
};

class EmbDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    EmbDetailsDialog(QGraphicsScene* theScene, QWidget *parent = 0);
    ~EmbDetailsDialog();

    QWidget* mainWidget;

    void getInfo();
    QWidget* createMainWidget();
    QWidget* createHistogram();

    QDialogButtonBox* buttonBox;

    unsigned int stitchesTotal;
    unsigned int stitchesReal;
    unsigned int stitchesJump;
    unsigned int stitchesTrim;
    unsigned int colorTotal;
    unsigned int colorChanges;

    QRectF boundingRect;
};

class MdiArea : public QMdiArea
{
    Q_OBJECT

public:
    MdiArea(MainWindow* mw, QWidget* parent = 0);
    ~MdiArea();

    void useBackgroundLogo(bool use);
    void useBackgroundTexture(bool use);
    void useBackgroundColor(bool use);

    void setBackgroundLogo(const QString& fileName);
    void setBackgroundTexture(const QString& fileName);
    void setBackgroundColor(const QColor& color);

    MainWindow* mainWin;

    int useLogo;
    int useTexture;
    int useColor;

    QPixmap bgLogo;
    QPixmap bgTexture;
    QColor  bgColor;

    void zoomExtentsAllSubWindows();
    void forceRepaint();

public slots:
    void cascade();
    void tile();
protected:
    virtual void mouseDoubleClickEvent(QMouseEvent* e);
    virtual void paintEvent(QPaintEvent* e);
};

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

    MdiArea*    getMdiArea();
    MainWindow* getApplication();
    MdiWindow*  activeMdiWindow();
    View*   activeView();
    QGraphicsScene* activeScene();

    virtual void    updateMenuToolbarStatusbar();

    MainWindow* mainWin;
    MdiArea*    mdiArea;
    PropertyEditor* dockPropEdit;
    StatusBar*  statusbar;

    QList<QGraphicsItem*> cutCopyObjectList;

    QHash<int, QAction*>    actionHash;
    QHash<QString, QToolBar*>   toolbarHash;
    QHash<QString, QMenu*>  menuHash;

    QString formatFilterOpen;
    QString formatFilterSave;

    QString platformString();

    QByteArray layoutState;

    int numOfDocs;
    int docIndex;

    QList<MdiWindow*> listMdiWin;
    QMdiSubWindow* findMdiWindow(const QString &fileName);
    QString openFilesPath;

    QAction* myFileSeparator;

    QWizard*    wizardTipOfTheDay;
    QLabel* labelTipOfTheDay;
    QCheckBox*  checkBoxTipOfTheDay;
    QStringList listTipOfTheDay;

    QComboBox* layerSelector;
    QComboBox* colorSelector;
    QComboBox* linetypeSelector;
    QComboBox* lineweightSelector;
    QFontComboBox* textFontSelector;
    QComboBox* textSizeSelector;
    void createViewMenu();
    void createSettingsMenu();
    void createWindowMenu();
    void createHelpMenu();

    void enableMoveRapidFire();
    void disableMoveRapidFire();

    void onCloseWindow();
    virtual void    onCloseMdiWin(MdiWindow*);

    void recentMenuAboutToShow();

    void onWindowActivated (QMdiSubWindow* w);
    void windowMenuAboutToShow();
    void windowMenuActivated(bool checked/*int id*/ );

    void    updateAllViewScrollBars(bool val);
    void    updateAllViewCrossHairColors(unsigned int color);
    void    updateAllViewBackgroundColors(unsigned int color);
    void    updateAllViewSelectBoxColors(unsigned int colorL, unsigned int fillL, unsigned int colorR, unsigned int fillR, int alpha);
    void    updateAllViewGridColors(unsigned int color);
    void    updateAllViewRulerColors(unsigned int color);

    void    updatePickAddMode(bool val);
    void    pickAddModeToggled();

    void    settingsDialog(const QString& showTab = QString());
    void    readSettings();
    void    writeSettings();

    static bool    validFileFormat(const QString &fileName);

    QAction*    createAction(const QString icon, const QString toolTip, const QString statusTip, bool scripted = false);

    void createAllToolbars();
    void createLayerToolbar();
    void createPropertiesToolbar();
    void createTextToolbar();

    void stub_testing();

    void newFile();
    void openFile(bool recent = false, const QString& recentFile = "");
    void openFilesSelected(const QStringList&);
    void openrecentfile();
    void savefile();
    void saveasfile();
    void print();
    void designDetails();
    void exit();
    void quit();
    void checkForUpdates();
    // Help Menu
    void tipOfTheDay();
    void buttonTipOfTheDayClicked(int);
    void checkBoxTipOfTheDayStateChanged(int);
    void help();
    void changelog();
    void about();
    void whatsThisContextHelp();

    void cut();
    void copy();
    void paste();
    void selectAll();

    void closeToolBar(QAction*);
    void floatingChangedToolBar(bool);

    void toggleGrid();
    void toggleRuler();
    void toggleLwt();

    // Icons
    void iconResize(int iconSize);

    //Selectors
    void layerSelectorIndexChanged(int index);
    void colorSelectorIndexChanged(int index);
    void linetypeSelectorIndexChanged(int index);
    void lineweightSelectorIndexChanged(int index);
    void textFontSelectorCurrentFontChanged(const QFont& font);
    void textSizeSelectorIndexChanged(int index);

    QString textFont();
    float   textSize();
    float   textAngle();
    bool    textBold();
    bool    textItalic();
    bool    textUnderline();
    bool    textStrikeOut();
    bool    textOverline();

    QString getCurrentLayer();
    unsigned int    getCurrentColor();
    QString getCurrentLineType();
    QString getCurrentLineWeight();

    // Standard Slots
    bool isShiftPressed();
    void setShiftPressed();
    void setShiftReleased();

    void deletePressed();
    void escapePressed();

    void setTextSize(float num);

    void nativeAddArc(float, float, float, float, float, float, int rubberMode);
    void nativeAddCircle(float centerX, float centerY, float radius, bool fill, int rubberMode);
    void nativeAddLine(float, float, float, float, float, int rubberMode);
    void nativeAddEllipse(float centerX, float centerY, float width, float height, float rot, bool fill, int rubberMode);
    void nativeAddPoint(float x, float y);
    void nativeAddPolygon(float startX, float startY, const QPainterPath& p, int rubberMode);
    void nativeAddTextSingle(const QString& str, float x, float y, float rot, bool fill, int rubberMode);
    void nativeAddPolyline(float startX, float startY, const QPainterPath& p, int rubberMode);
    void nativeAddRectangle(float x, float y, float w, float h, float rot, bool fill, int rubberMode);
    void nativeAddDimLeader(float x1, float y1, float x2, float y2, float rot, int rubberMode);
    
    float nativeCalculateAngle(float x1, float y1, float x2, float y2);
    float nativeCalculateDistance(float x1, float y1, float x2, float y2);
    float nativePerpendicularDistance(float px, float py, float x1, float y1, float x2, float y2);

    virtual void    resizeEvent(QResizeEvent*);
    void    closeEvent(QCloseEvent *event);
    QAction*    getFileSeparator();
    void    loadFormats();

public slots:
    void actions();
};

class PreviewDialog : public QFileDialog
{
    Q_OBJECT

public:
    PreviewDialog(QWidget* parent = 0,
  const QString& caption = QString(),
  const QString& directory = QString(),
  const QString& filter = QString());
    ~PreviewDialog();

private:
    ImageWidget* imgWidget;
};

void toPolyline(EmbPattern* pattern, const QPointF& objPos, const QPainterPath& objPath, const QString& layer, const QColor& color, const QString& lineType, const QString& lineWeight);

class PropertyEditor : public QDockWidget
{
    Q_OBJECT

public:
    PropertyEditor(const QString& iconDirectory = QString(), bool pickAddMode = true, QWidget* widgetToFocus = 0, QWidget* parent = 0, Qt::WindowFlags flags = Qt::Widget);
    ~PropertyEditor();

    QGroupBox*   createGroupBoxMiscImage();
    QGroupBox*   createGroupBoxGeneral();
    QGroupBox*   createGroupBoxGeometryArc();
    QGroupBox*   createGroupBoxMiscArc();
    QGroupBox*   createGroupBoxGeometryBlock();
    QGroupBox*   createGroupBoxGeometryCircle();
    QGroupBox*   createGroupBoxGeometryDimAligned();
    QGroupBox*   createGroupBoxGeometryDimAngular();
    QGroupBox*   createGroupBoxGeometryDimArcLength();
    QGroupBox*   createGroupBoxGeometryDimDiameter();
    QGroupBox*   createGroupBoxGeometryDimLeader();
    QGroupBox*   createGroupBoxGeometryDimLinear();
    QGroupBox*   createGroupBoxGeometryDimOrdinate();
    QGroupBox*   createGroupBoxGeometryDimRadius();
    QGroupBox*   createGroupBoxGeometryEllipse();
    QGroupBox*   createGroupBoxGeometryImage();
    QGroupBox*   createGroupBoxGeometryInfiniteLine();
    QGroupBox*   createGroupBoxGeometryLine();
    QGroupBox*   createGroupBoxGeometryPath();
    QGroupBox*   createGroupBoxMiscPath();
    QGroupBox*   createGroupBoxGeometryPoint();
    QGroupBox*   createGroupBoxGeometryPolygon();
    QGroupBox*   createGroupBoxGeometryPolyline();
    QGroupBox*   createGroupBoxMiscPolyline();
    QGroupBox*   createGroupBoxGeometryRay();
    QGroupBox*   createGroupBoxGeometryRectangle();
    QGroupBox*   createGroupBoxGeometryTextMulti();
    QGroupBox*   createGroupBoxTextTextSingle();
    QGroupBox*   createGroupBoxGeometryTextSingle();
    QGroupBox*   createGroupBoxMiscTextSingle();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

signals:
    void pickAddModeToggled();

public slots:
    void setSelectedItems(QList<QGraphicsItem*> itemList);
    void updatePickAddModeButton(bool pickAddMode);

private slots:
    void fieldEdited(QObject* fieldObj);
    void showGroups(int objType);
    void showOneType(int index);
    void hideAllGroups();
    void clearAllFields();
    void togglePickAddMode();

private:
    QWidget* focusWidget;

    QString  iconDir;
    int  iconSize;
    Qt::ToolButtonStyle propertyEditorButtonStyle;

    int pickAdd;

    QList<QGraphicsItem*> selectedItemList;

    //Helper functions
    QToolButton*   createToolButton(const QString& iconName, const QString& txt);
    QLineEdit* createLineEdit(const QString& validatorType = QString(), bool readOnly = false);
    QComboBox* createComboBox(bool disable = false);
    QFontComboBox* createFontComboBox(bool disable = false);


    void updateLineEditStrIfVaries(QLineEdit* lineEdit, const QString& str);
    void updateLineEditNumIfVaries(QLineEdit* lineEdit, float num, bool useAnglePrecision);
    void updateFontComboBoxStrIfVaries(QFontComboBox* fontComboBox, const QString& str);
    void updateComboBoxStrIfVaries(QComboBox* comboBox, const QString& str, const QStringList& strList);
    void updateComboBoxBoolIfVaries(QComboBox* comboBox, bool val, bool yesOrNoText);

    QSignalMapper* signalMapper;
    void mapSignal(QObject* fieldObj, const QString& name, QVariant value);

    QComboBox*   createComboBoxSelected();
    QToolButton* createToolButtonQSelect();
    QToolButton* createToolButtonPickAdd();

    QComboBox*   comboBoxSelected;
    QToolButton* toolButtonQSelect;
    QToolButton* toolButtonPickAdd;

    //TODO: Alphabetic/Categorized TabWidget

};

class SelectBox : public QRubberBand
{
    Q_OBJECT

public:
    SelectBox(Shape s, QWidget* parent = 0);

    EmbColor leftBrushColor;
    QColor rightBrushColor;
    QColor leftPenColor;
    QColor rightPenColor;
    unsigned char alpha;

    QBrush dirBrush;
    QBrush leftBrush;
    QBrush rightBrush;

    QPen dirPen;
    QPen leftPen;
    QPen rightPen;

    int boxDir;

public slots:
    void setDirection(int dir);
    void setColors(const QColor& colorL, const QColor& fillL, const QColor& colorR, const QColor& fillR, int newAlpha);

protected:
    void paintEvent(QPaintEvent*);

private:
    void forceRepaint();
};

class Settings_Dialog : public QDialog
{
    Q_OBJECT

public:
    Settings_Dialog(MainWindow* mw, const QString& showTab = QString(), QWidget *parent = 0);
    ~Settings_Dialog();

    MainWindow*   mainWin;

    QTabWidget*   tabWidget;

    QDialogButtonBox* buttonBox;

    void addColorsToComboBox(QComboBox* comboBox);

    /* Functions */
    QWidget* createTabGeneral();
    QWidget* createTabFilesPaths();
    QWidget* createTabDisplay();
    QWidget* createTabOpenSave();
    QWidget* createTabPrinting();
    QWidget* createTabSnap();
    QWidget* createTabGridRuler();
    QWidget* createTabOrthoPolar();
    QWidget* createTabQuickSnap();
    QWidget* createTabQuickTrack();
    QWidget* createTabLineWeight();
    QWidget* createTabSelection();

private slots:
    void comboBoxLanguageCurrentIndexChanged(const QString&);
    void comboBoxIconThemeCurrentIndexChanged(const QString&);
    void comboBoxIconSizeCurrentIndexChanged(int);
    void checkBoxGeneralMdiBGUseLogoStateChanged(int);
    void chooseGeneralMdiBackgroundLogo();
    void checkBoxGeneralMdiBGUseTextureStateChanged(int);
    void chooseGeneralMdiBackgroundTexture();
    void checkBoxGeneralMdiBGUseColorStateChanged(int);
    void chooseGeneralMdiBackgroundColor();
    void currentGeneralMdiBackgroundColorChanged(const QColor&);
    void checkBoxTipOfTheDayStateChanged(int);
    void checkBoxUseOpenGLStateChanged(int);
    void checkBoxRenderHintAAStateChanged(int);
    void checkBoxRenderHintTextAAStateChanged(int);
    void checkBoxRenderHintSmoothPixStateChanged(int);
    void checkBoxRenderHintHighAAStateChanged(int);
    void checkBoxRenderHintNonCosmeticStateChanged(int);
    void checkBoxShowScrollBarsStateChanged(int);
    void comboBoxScrollBarWidgetCurrentIndexChanged(int);
    void spinBoxZoomScaleInValueChanged(double);
    void spinBoxZoomScaleOutValueChanged(double);
    void checkBoxDisableBGStateChanged(int);
    void chooseDisplayCrossHairColor();
    void currentDisplayCrossHairColorChanged(const QColor&);
    void chooseDisplayBackgroundColor();
    void currentDisplayBackgroundColorChanged(const QColor&);
    void chooseDisplaySelectBoxLeftColor();
    void currentDisplaySelectBoxLeftColorChanged(const QColor&);
    void chooseDisplaySelectBoxLeftFill();
    void currentDisplaySelectBoxLeftFillChanged(const QColor&);
    void chooseDisplaySelectBoxRightColor();
    void currentDisplaySelectBoxRightColorChanged(const QColor&);
    void chooseDisplaySelectBoxRightFill();
    void currentDisplaySelectBoxRightFillChanged(const QColor&);
    void spinBoxDisplaySelectBoxAlphaValueChanged(int);
    void checkBoxCustomFilterStateChanged(int);
    void buttonCustomFilterSelectAllClicked();
    void buttonCustomFilterClearAllClicked();
    void spinBoxRecentMaxFilesValueChanged(int);
    void spinBoxTrimDstNumJumpsValueChanged(int);
    void checkBoxGridShowOnLoadStateChanged(int);
    void checkBoxGridShowOriginStateChanged(int);
    void checkBoxGridColorMatchCrossHairStateChanged(int);
    void chooseGridColor();
    void currentGridColorChanged(const QColor&);
    void checkBoxGridLoadFromFileStateChanged(int);
    void comboBoxGridTypeCurrentIndexChanged(const QString&);
    void checkBoxGridCenterOnOriginStateChanged(int);
    void spinBoxGridCenterXValueChanged(double);
    void spinBoxGridCenterYValueChanged(double);
    void spinBoxGridSizeXValueChanged(double);
    void spinBoxGridSizeYValueChanged(double);
    void spinBoxGridSpacingXValueChanged(double);
    void spinBoxGridSpacingYValueChanged(double);
    void spinBoxGridSizeRadiusValueChanged(double);
    void spinBoxGridSpacingRadiusValueChanged(double);
    void spinBoxGridSpacingAngleValueChanged(double);
    void checkBoxRulerShowOnLoadStateChanged(int);
    void comboBoxRulerMetricCurrentIndexChanged(int);
    void chooseRulerColor();
    void currentRulerColorChanged(const QColor&);
    void spinBoxRulerPixelSizeValueChanged(double);
    void checkBoxQSnapEndPointStateChanged(int);
    void checkBoxQSnapMidPointStateChanged(int);
    void checkBoxQSnapCenterStateChanged(int);
    void checkBoxQSnapNodeStateChanged(int);
    void checkBoxQSnapQuadrantStateChanged(int);
    void checkBoxQSnapIntersectionStateChanged(int);
    void checkBoxQSnapExtensionStateChanged(int);
    void checkBoxQSnapInsertionStateChanged(int);
    void checkBoxQSnapPerpendicularStateChanged(int);
    void checkBoxQSnapTangentStateChanged(int);
    void checkBoxQSnapNearestStateChanged(int);
    void checkBoxQSnapApparentStateChanged(int);
    void checkBoxQSnapParallelStateChanged(int);
    void buttonQSnapSelectAllClicked();
    void buttonQSnapClearAllClicked();
    void comboBoxQSnapLocatorColorCurrentIndexChanged(int);
    void sliderQSnapLocatorSizeValueChanged(int);
    void sliderQSnapApertureSizeValueChanged(int);
    void checkBoxLwtShowLwtStateChanged(int);
    void checkBoxLwtRealRenderStateChanged(int);
    void checkBoxSelectionModePickFirstStateChanged(int);
    void checkBoxSelectionModePickAddStateChanged(int);
    void checkBoxSelectionModePickDragStateChanged(int);
    void comboBoxSelectionCoolGripColorCurrentIndexChanged(int);
    void comboBoxSelectionHotGripColorCurrentIndexChanged(int);
    void sliderSelectionGripSizeValueChanged(int);
    void sliderSelectionPickBoxSizeValueChanged(int);

    void acceptChanges();
    void rejectChanges();

signals:
    void buttonCustomFilterSelectAll(bool);
    void buttonCustomFilterClearAll(bool);
    void buttonQSnapSelectAll(bool);
    void buttonQSnapClearAll(bool);
};

class StatusBarButton : public QToolButton
{
    Q_OBJECT

public:
    StatusBarButton(QString buttonText, MainWindow* mw, StatusBar* statbar, QWidget *parent = 0);

protected:
    void contextMenuEvent(QContextMenuEvent *event = 0);

private slots:
    void settingsSnap();
    void settingsGrid();
    void settingsRuler();
    void settingsOrtho();
    void settingsPolar();
    void settingsQSnap();
    void settingsQTrack();
    void settingsLwt();
    void toggleSnap(bool on);
    void toggleGrid(bool on);
    void toggleRuler(bool on);
    void toggleOrtho(bool on);
    void togglePolar(bool on);
    void toggleQSnap(bool on);
    void toggleQTrack(bool on);
    void toggleLwt(bool on);
public slots:
    void enableLwt();
    void disableLwt();
    void enableReal();
    void disableReal();

private:
    MainWindow* mainWin;
    StatusBar*  statusbar;
};

class StatusBar : public QStatusBar
{
    Q_OBJECT

public:
    StatusBar(MainWindow* mw, QWidget* parent = 0);

    void setMouseCoord(float x, float y);

};

class View : public QGraphicsView
{
    Q_OBJECT

public:
    View(MainWindow* mw, QGraphicsScene* theScene, QWidget* parent);
    ~View();

    bool allowZoomIn();
    bool allowZoomOut();

    void recalculateLimits();
    void zoomToPoint(const QPoint& mousePoint, int zoomDir);
    void centerAt(const QPointF& centerPoint);
    QPointF center() { return mapToScene(rect().center()); }

    void addObject(BaseObject* obj);
    void deleteObject(BaseObject* obj);
    void vulcanizeObject(BaseObject* obj);

public slots:
    void zoomIn();
    void zoomOut();
    void zoomWindow();
    void zoomSelected();
    void zoomExtents();
    void panRealTime();
    void panPoint();
    void panLeft();
    void panRight();
    void panUp();
    void panDown();
    void selectAll();
    void selectionChanged();
    void clearSelection();
    void deleteSelected();
    void moveSelected(float dx, float dy);
    void cut();
    void copy();
    void paste();
    void repeatAction();
    void moveAction();
    void scaleAction();
    void scaleSelected(float x, float y, float factor);
    void rotateAction();
    void rotateSelected(float x, float y, float rot);
    void mirrorSelected(float x1, float y1, float x2, float y2);
    int  numSelected();

    void deletePressed();
    void escapePressed();

    void cornerButtonClicked();

    void showScrollBars(bool val);
    void setCornerButton();
    void setCrossHairColor(unsigned int color);
    void setCrossHairSize(unsigned char percent);
    void setBackgroundColor(unsigned int color);
    void setSelectBoxColors(unsigned int colorL, unsigned int fillL, unsigned int colorR, unsigned int fillR, int alpha);
    void toggleSnap(bool on);
    void toggleGrid(bool on);
    void toggleRuler(bool on);
    void toggleOrtho(bool on);
    void togglePolar(bool on);
    void toggleQSnap(bool on);
    void toggleQTrack(bool on);
    void toggleLwt(bool on);
    void toggleReal(bool on);
    bool isLwtEnabled();
    bool isRealEnabled();

    void setGridColor(unsigned int color);
    void createGrid(const QString& gridType);
    void setRulerColor(unsigned int color);

    void previewOn(int clone, int mode, float x, float y, float data);
    void previewOff();

    void enableMoveRapidFire();
    void disableMoveRapidFire();

    bool allowRubber();
    void addToRubberRoom(QGraphicsItem* item);
    void vulcanizeRubberRoom();
    void clearRubberRoom();
    void spareRubber(int id);
    void setRubberMode(int mode);
    void setRubberPoint(const QString& key, const QPointF& point);
    void setRubberText(const QString& key, const QString& txt);

protected:
    void mouseDoubleClickEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void contextMenuEvent(QContextMenuEvent* event);
    void drawBackground(QPainter* painter, const QRectF& rect);
    void drawForeground(QPainter* painter, const QRectF& rect);
    void enterEvent(QEvent* event);

private:
    QHash<int, QGraphicsItem*> hashDeletedObjects;

    QList<int> spareRubberList;

    QColor gridColor;
    QPainterPath gridPath;
    void createGridRect();
    void createGridPolar();
    void createGridIso();
    QPainterPath originPath;
    void createOrigin();

    void loadRulerSettings();

    bool willUnderflowInt32(int a, int b);
    bool willOverflowInt32(int a, int b);
    int roundToMultiple(bool roundUp, int numToRound, int multiple);
    QPainterPath createRulerTextPath(float x, float y, QString str, float height);

    QList<QGraphicsItem*> previewObjectList;
    QGraphicsItemGroup* previewObjectItemGroup;
    QPointF previewPoint;
    float previewData;
    int previewMode;

    QList<QGraphicsItem*> createObjectList(QList<QGraphicsItem*> list);
    QPointF cutCopyMousePoint;
    QGraphicsItemGroup* pasteObjectItemGroup;

    QList<QGraphicsItem*> rubberRoomList;

    void copySelected();

    void startGripping(BaseObject* obj);
    void stopGripping(bool accept = false);

    BaseObject* gripBaseObj;
    BaseObject* tempBaseObj;

    MainWindow* mainWin;
    QGraphicsScene* gscene;

    SelectBox* selectBox;

    void updateMouseCoords(int x, int y);

    void panStart(const QPoint& point);
    int panDistance;
    int panStartX;
    int panStartY;

    void alignScenePointWithViewPoint(const QPointF& scenePoint, const QPoint& viewPoint);
};

class BaseObject : public QGraphicsPathItem
{
public:
    BaseObject(QGraphicsItem* parent = 0);
    virtual ~BaseObject();

    enum { Type = OBJ_TYPE_BASE };
    virtual int type() const { return Type; }

    QPen objectPen()   const { return objPen; }
    QColor   objectColor() const { return objPen.color(); }
    unsigned int objectColorRGB()  const { return objPen.color().rgb(); }
    Qt::PenStyle objectLineType()  const { return objPen.style(); }
    float    objectLineWeight()    const { return lwtPen.widthF(); }
    QPainterPath objectPath()  const { return path(); }
    int  objectRubberMode()    const { return objRubberMode; }
    QPointF  objectRubberPoint(const QString& key) const;
    QString  objectRubberText(const QString& key) const;

    QRectF rect() const { return path().boundingRect(); }
    void setRect(const QRectF& r) { QPainterPath p; p.addRect(r); setPath(p); }
    void setRect(float x, float y, float w, float h) { QPainterPath p; p.addRect(x,y,w,h); setPath(p); }
    QLineF line() const { return objLine; }
    void setLine(const QLineF& li) { QPainterPath p; p.moveTo(li.p1()); p.lineTo(li.p2()); setPath(p); objLine = li; }
    void setLine(float x1, float y1, float x2, float y2) { QPainterPath p; p.moveTo(x1,y1); p.lineTo(x2,y2); setPath(p); objLine.setLine(x1,y1,x2,y2); }

    void setObjectColor(const QColor& color);
    void setObjectColorRGB(unsigned int rgb);
    void setObjectLineType(Qt::PenStyle lineType);
    void setObjectLineWeight(float lineWeight);
    void setObjectPath(const QPainterPath& p) { setPath(p); }
    void setObjectRubberMode(int mode) { objRubberMode = mode; }
    void setObjectRubberPoint(const QString& key, const QPointF& point) { objRubberPoints.insert(key, point); }
    void setObjectRubberText(const QString& key, const QString& txt) { objRubberTexts.insert(key, txt); }

    virtual QRectF boundingRect() const;
    virtual QPainterPath shape() const { return path(); }

    void drawRubberLine(const QLineF& rubLine, QPainter* painter = 0, const char* colorFromScene = 0);

    virtual void vulcanize() = 0;
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint) = 0;
    virtual QList<QPointF> allGripPoints() = 0;
    virtual void gripEdit(const QPointF& before, const QPointF& after) = 0;
    
    QPen objPen;
    QPen lwtPen;
    QLineF objLine;
    int objRubberMode;
    QHash<QString, QPointF> objRubberPoints;
    QHash<QString, QString> objRubberTexts;
    int objID;
protected:
    QPen lineWeightPen() const { return lwtPen; }
    void realRender(QPainter* painter, const QPainterPath& renderPath);
};

class ArcObject : public BaseObject
{
public:
    ArcObject(float startX, float startY, float midX, float midY, float endX, float endY, unsigned int rgb, QGraphicsItem* parent = 0);
    ArcObject(ArcObject* obj, QGraphicsItem* parent = 0);
    ~ArcObject();

    enum { Type = OBJ_TYPE_ARC };
    virtual int type() const { return Type; }

    QPointF objectCenter()    const { return scenePos(); }
    float   objectRadius()    const { return rect().width()/2.0*scale(); }
    float   objectStartAngle()    const;
    float   objectEndAngle()  const;
    QPointF objectStartPoint()    const;
    QPointF objectMidPoint()  const;
    QPointF objectEndPoint()  const;
    float   objectArea()  const;
    float   objectArcLength() const;
    float   objectChord() const;
    float   objectIncludedAngle() const;
    bool    objectClockwise() const;

    void setObjectRadius(float radius);
    void setObjectStartAngle(float angle);
    void setObjectEndAngle(float angle);
    void setObjectStartPoint(float pointX, float pointY);
    void setObjectMidPoint(const QPointF& point);
    void setObjectMidPoint(float pointX, float pointY);
    void setObjectEndPoint(const QPointF& point);
    void setObjectEndPoint(float pointX, float pointY);

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(float startX, float startY, float midX, float midY, float endX, float endY, unsigned int rgb, Qt::PenStyle lineType);
    void updatePath();

    void calculateArcData(float startX, float startY, float midX, float midY, float endX, float endY);
    void updateArcRect(float radius);

    QPointF arcStartPoint;
    QPointF arcMidPoint;
    QPointF arcEndPoint;
};

class CircleObject : public BaseObject
{
public:
    CircleObject(float centerX, float centerY, float radius, unsigned int rgb, QGraphicsItem* parent = 0);
    CircleObject(CircleObject* obj, QGraphicsItem* parent = 0);
    ~CircleObject();

    enum { Type = OBJ_TYPE_CIRCLE };
    virtual int type() const { return Type; }

    QPainterPath objectSavePath() const;

    QPointF objectCenter()    const { return scenePos(); }
    float   objectRadius()    const { return rect().width()/2.0*scale(); }
    float   objectDiameter()  const { return rect().width()*scale(); }
    float   objectArea()  const { return embConstantPi*objectRadius()*objectRadius(); }
    float   objectCircumference() const { return embConstantPi*objectDiameter(); }
    QPointF objectQuadrant0() const { return objectCenter() + QPointF(objectRadius(), 0); }
    QPointF objectQuadrant90()    const { return objectCenter() + QPointF(0,-objectRadius()); }
    QPointF objectQuadrant180()   const { return objectCenter() + QPointF(-objectRadius(),0); }
    QPointF objectQuadrant270()   const { return objectCenter() + QPointF(0, objectRadius()); }

    void setObjectRadius(float radius);
    void setObjectDiameter(float diameter);
    void setObjectArea(float area);
    void setObjectCircumference(float circumference);

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(float centerX, float centerY, float radius, unsigned int rgb, Qt::PenStyle lineType);
    void updatePath();
};

class DimLeaderObject : public BaseObject
{
public:
    DimLeaderObject(float x1, float y1, float x2, float y2, unsigned int rgb, QGraphicsItem* parent = 0);
    DimLeaderObject(DimLeaderObject* obj, QGraphicsItem* parent = 0);
    ~DimLeaderObject();

    enum ArrowStyle
    {
    NoArrow, /* NOTE: Allow this enum to evaluate false. */
    Open,
    Closed,
    Dot,
    Box,
    Tick
    };

    enum lineStyle
    {
    NoLine, /* NOTE: Allow this enum to evaluate false. */
    Flared,
    Fletching
    };

    enum { Type = OBJ_TYPE_DIMLEADER };
    virtual int type() const { return Type; }

    QPointF objectEndPoint1() const;
    QPointF objectEndPoint2() const;
    QPointF objectMidPoint()  const;
    float   objectX1()    const { return objectEndPoint1().x(); }
    float   objectY1()    const { return objectEndPoint1().y(); }
    float   objectX2()    const { return objectEndPoint2().x(); }
    float   objectY2()    const { return objectEndPoint2().y(); }
    float   objectDeltaX()    const { return (objectEndPoint2().x() - objectEndPoint1().x()); }
    float   objectDeltaY()    const { return (objectEndPoint2().y() - objectEndPoint1().y()); }
    float   objectAngle() const;
    float   objectLength()    const { return line().length(); }

    void setObjectEndPoint1(EmbVector v);
    void setObjectEndPoint2(EmbVector v);

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(float x1, float y1, float x2, float y2, unsigned int rgb, Qt::PenStyle lineType);

    int curved;
    int filled;
    void updateLeader();
    QPainterPath lineStylePath;
    QPainterPath arrowStylePath;
    float arrowStyleAngle;
    float arrowStyleLength;
    float lineStyleAngle;
    float lineStyleLength;
};

class EllipseObject : public BaseObject
{
public:
    EllipseObject(float centerX, float centerY, float width, float height, unsigned int rgb, QGraphicsItem* parent = 0);
    EllipseObject(EllipseObject* obj, QGraphicsItem* parent = 0);
    ~EllipseObject();

    enum { Type = OBJ_TYPE_ELLIPSE };
    virtual int type() const { return Type; }

    QPainterPath objectSavePath() const;

    QPointF objectCenter() const { return scenePos(); }
    float   objectRadiusMajor()   const { return qMax(rect().width(), rect().height())/2.0*scale(); }
    float   objectRadiusMinor()   const { return qMin(rect().width(), rect().height())/2.0*scale(); }
    float   objectDiameterMajor() const { return qMax(rect().width(), rect().height())*scale(); }
    float   objectDiameterMinor() const { return qMin(rect().width(), rect().height())*scale(); }
    float   objectWidth() const { return rect().width()*scale(); }
    float   objectHeight()    const { return rect().height()*scale(); }
    QPointF objectQuadrant0() const;
    QPointF objectQuadrant90()    const;
    QPointF objectQuadrant180()   const;
    QPointF objectQuadrant270()   const;

    void setObjectSize(float width, float height);
    void setObjectRadiusMajor(float radius);
    void setObjectRadiusMinor(float radius);
    void setObjectDiameterMajor(float diameter);
    void setObjectDiameterMinor(float diameter);

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(float centerX, float centerY, float width, float height, unsigned int rgb, Qt::PenStyle lineType);
    void updatePath();
};

class ImageObject : public BaseObject
{
public:
    ImageObject(float x, float y, float w, float h, unsigned int rgb, QGraphicsItem* parent = 0);
    ImageObject(ImageObject* obj, QGraphicsItem* parent = 0);
    ~ImageObject();

    enum { Type = OBJ_TYPE_IMAGE };
    virtual int type() const { return Type; }

    QPointF objectTopLeft() const;
    QPointF objectTopRight()    const;
    QPointF objectBottomLeft()  const;
    QPointF objectBottomRight() const;
    float   objectWidth()   const { return rect().width()*scale(); }
    float   objectHeight()  const { return rect().height()*scale(); }
    float   objectArea()    const { return qAbs(objectWidth()*objectHeight()); }

    void setObjectRect(float x, float y, float w, float h);

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(float x, float y, float w, float h, unsigned int rgb, Qt::PenStyle lineType);
    void updatePath();
};


class LineObject : public BaseObject
{
public:
    LineObject(float x1, float y1, float x2, float y2, unsigned int rgb, QGraphicsItem* parent = 0);
    LineObject(LineObject* obj, QGraphicsItem* parent = 0);
    ~LineObject();

    enum { Type = OBJ_TYPE_LINE };
    virtual int type() const { return Type; }

    QPainterPath objectSavePath() const;

    QPointF objectEndPoint1() const { return scenePos(); }
    QPointF objectEndPoint2() const;
    QPointF objectMidPoint()  const;
    float   objectX1()    const { return objectEndPoint1().x(); }
    float   objectY1()    const { return objectEndPoint1().y(); }
    float   objectX2()    const { return objectEndPoint2().x(); }
    float   objectY2()    const { return objectEndPoint2().y(); }
    float   objectDeltaX()    const { return (objectEndPoint2().x() - objectEndPoint1().x()); }
    float   objectDeltaY()    const { return (objectEndPoint2().y() - objectEndPoint1().y()); }
    float   objectAngle() const;
    float   objectLength()    const { return line().length()*scale(); }

    void setObjectEndPoint1(const QPointF& endPt1);
    void setObjectEndPoint1(float x1, float y1);
    void setObjectEndPoint2(const QPointF& endPt2);
    void setObjectEndPoint2(float x2, float y2);
    void setObjectX1(float x) { setObjectEndPoint1(x, objectEndPoint1().y()); }
    void setObjectY1(float y) { setObjectEndPoint1(objectEndPoint1().x(), y); }
    void setObjectX2(float x) { setObjectEndPoint2(x, objectEndPoint2().y()); }
    void setObjectY2(float y) { setObjectEndPoint2(objectEndPoint2().x(), y); }

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(float x1, float y1, float x2, float y2, unsigned int rgb, Qt::PenStyle lineType);
};

class PathObject : public BaseObject
{
public:
    PathObject(float x, float y, const QPainterPath p, unsigned int rgb, QGraphicsItem* parent = 0);
    PathObject(PathObject* obj, QGraphicsItem* parent = 0);
    ~PathObject();

    enum { Type = OBJ_TYPE_PATH };
    virtual int type() const { return Type; }

    QPainterPath objectCopyPath() const;
    QPainterPath objectSavePath() const;

    QPointF objectPos() const { return scenePos(); }
    float   objectX()   const { return scenePos().x(); }
    float   objectY()   const { return scenePos().y(); }

    void setObjectPos(const QPointF& point) { setPos(point.x(), point.y()); }
    void setObjectPos(float x, float y) { setPos(x, y); }
    void setObjectX(float x) { setObjectPos(x, objectY()); }
    void setObjectY(float y) { setObjectPos(objectX(), y); }

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(float x, float y, const QPainterPath& p, unsigned int rgb, Qt::PenStyle lineType);
    void updatePath(const QPainterPath& p);
    QPainterPath normalPath;
    //TODO: make paths similar to polylines. Review and implement any missing functions/members.
};

class PointObject : public BaseObject
{
public:
    PointObject(float x, float y, unsigned int rgb, QGraphicsItem* parent = 0);
    PointObject(PointObject* obj, QGraphicsItem* parent = 0);
    ~PointObject();

    enum { Type = OBJ_TYPE_POINT };
    virtual int type() const { return Type; }

    QPainterPath objectSavePath() const;

    QPointF objectPos() const { return scenePos(); }
    float   objectX()   const { return scenePos().x(); }
    float   objectY()   const { return scenePos().y(); }

    void setObjectPos(const QPointF& point) { setPos(point.x(), point.y()); }
    void setObjectPos(float x, float y) { setPos(x, y); }
    void setObjectX(float x) { setObjectPos(x, objectY()); }
    void setObjectY(float y) { setObjectPos(objectX(), y); }

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(float x, float y, unsigned int rgb, Qt::PenStyle lineType);
};


class PolygonObject : public BaseObject
{
public:
    PolygonObject(float x, float y, const QPainterPath& p, unsigned int rgb, QGraphicsItem* parent = 0);
    PolygonObject(PolygonObject* obj, QGraphicsItem* parent = 0);
    ~PolygonObject();

    enum { Type = OBJ_TYPE_POLYGON };
    virtual int type() const { return Type; }

    QPainterPath objectCopyPath() const;
    QPainterPath objectSavePath() const;

    QPointF objectPos() const { return scenePos(); }
    float   objectX()   const { return scenePos().x(); }
    float   objectY()   const { return scenePos().y(); }

    void setObjectPos(const QPointF& point) { setPos(point.x(), point.y()); }
    void setObjectPos(float x, float y) { setPos(x, y); }
    void setObjectX(float x) { setObjectPos(x, objectY()); }
    void setObjectY(float y) { setObjectPos(objectX(), y); }

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(float x, float y, const QPainterPath& p, unsigned int rgb, Qt::PenStyle lineType);
    void updatePath(const QPainterPath& p);
    QPainterPath normalPath;
    int findIndex(const QPointF& point);
    int gripIndex;
};


class PolylineObject : public BaseObject
{
public:
    PolylineObject(float x, float y, const QPainterPath& p, unsigned int rgb, QGraphicsItem* parent = 0);
    PolylineObject(PolylineObject* obj, QGraphicsItem* parent = 0);
    ~PolylineObject();

    enum { Type = OBJ_TYPE_POLYLINE };
    virtual int type() const { return Type; }

    QPainterPath objectCopyPath() const;
    QPainterPath objectSavePath() const;

    QPointF objectPos() const { return scenePos(); }
    float   objectX()   const { return scenePos().x(); }
    float   objectY()   const { return scenePos().y(); }

    void setObjectPos(const QPointF& point) { setPos(point.x(), point.y()); }
    void setObjectPos(float x, float y) { setPos(x, y); }
    void setObjectX(float x) { setObjectPos(x, objectY()); }
    void setObjectY(float y) { setObjectPos(objectX(), y); }

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(float x, float y, const QPainterPath& p, unsigned int rgb, Qt::PenStyle lineType);
    void updatePath(const QPainterPath& p);
    QPainterPath normalPath;
    int findIndex(const QPointF& point);
    int gripIndex;
};


class RectObject : public BaseObject
{
public:
    RectObject(float x, float y, float w, float h, unsigned int rgb, QGraphicsItem* parent = 0);
    RectObject(RectObject* obj, QGraphicsItem* parent = 0);
    ~RectObject();

    enum { Type = OBJ_TYPE_RECTANGLE };
    virtual int type() const { return Type; }

    QPainterPath objectSavePath() const;

    QPointF objectPos() const { return scenePos(); }

    QPointF objectTopLeft() const;
    QPointF objectTopRight()    const;
    QPointF objectBottomLeft()  const;
    QPointF objectBottomRight() const;
    float   objectWidth()   const { return rect().width()*scale(); }
    float   objectHeight()  const { return rect().height()*scale(); }
    float   objectArea()    const { return qAbs(objectWidth()*objectHeight()); }

    void setObjectRect(float x, float y, float w, float h);

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(float x, float y, float w, float h, unsigned int rgb, Qt::PenStyle lineType);
    void updatePath();
};


class TextSingleObject : public BaseObject
{
public:
    TextSingleObject(const QString& str, float x, float y, unsigned int rgb, QGraphicsItem* parent = 0);
    TextSingleObject(TextSingleObject* obj, QGraphicsItem* parent = 0);
    ~TextSingleObject();

    enum { Type = OBJ_TYPE_TEXTSINGLE };
    virtual int type() const { return Type; }

    QList<QPainterPath> objectSavePathList() const { return subPathList(); }
    QList<QPainterPath> subPathList() const;

    QPointF objectPos()    const { return scenePos(); }
    float   objectX()  const { return scenePos().x(); }
    float   objectY()  const { return scenePos().y(); }

    QStringList objectTextJustifyList() const;

    void setObjectText(const QString& str);
    void setObjectTextFont(const QString& font);
    void setObjectTextJustify(const QString& justify);
    void setObjectTextSize(float size);
    void setObjectTextStyle(bool bold, bool italic, bool under, bool strike, bool over);
    void setObjectTextBold(bool val);
    void setObjectTextItalic(bool val);
    void setObjectTextUnderline(bool val);
    void setObjectTextStrikeOut(bool val);
    void setObjectTextOverline(bool val);
    void setObjectTextBackward(bool val);
    void setObjectTextUpsideDown(bool val);
    void setObjectPos(const QPointF& point) { setPos(point.x(), point.y()); }
    void setObjectPos(float x, float y) { setPos(x, y); }
    void setObjectX(float x) { setObjectPos(x, objectY()); }
    void setObjectY(float y) { setObjectPos(objectX(), y); }

    void updateRubber(QPainter* painter = 0);
    virtual void vulcanize();
    virtual QPointF mouseSnapPoint(const QPointF& mousePoint);
    virtual QList<QPointF> allGripPoints();
    virtual void gripEdit(const QPointF& before, const QPointF& after);

    QString objText;
    QString objTextFont;
    QString objTextJustify;
    float objTextSize;
    int objTextBold;
    int objTextItalic;
    int    objTextUnderline;
    int    objTextStrikeOut;
    int    objTextOverline;
    int    objTextBackward;
    int    objTextUpsideDown;
    QPainterPath objTextPath;
protected:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
private:
    void init(const QString& str, float x, float y, unsigned int rgb, Qt::PenStyle lineType);
};

#endif
#endif
#endif /* EMBROIDERMODDER_H */

