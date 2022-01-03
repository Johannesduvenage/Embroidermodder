/* This file is part of Embroidermodder 2.
 * ------------------------------------------------------------
 * Copyright 2021-2022 The Embroidermodder Team
 * Embroidermodder 2 is Open Source Software.
 * See LICENSE.txt for licensing terms.
 * ------------------------------------------------------------
 * This file is for the in-progress translation of the action
 * system into C without dependencies.
 */

#include "embroidermodder.h"

#include <stdlib.h>
#include <string.h>

action_call undo_history[1000];
action_call action;
int undo_history_length = 0;
int undo_history_position = 0;

void doNothing(void)
{
    /* This function intentionally does nothing. */
    debug_message("doNothing()");
}

void main_undo(void)
{
    debug_message("undo()");
    if (undo_history_position > 0) {
        action_call last = undo_history[undo_history_position];
        undo_history_position--;
        printf("undo_history_position = %d\n", undo_history_position);
        printf("undo_history_length = %d\n", undo_history_length);
        
        /* Create the reverse action from the last action and apply with
         * the main actuator.
         */
        switch (last.id) {
        case ACTION_donothing:
        default:
            debug_message("The last action has no undo candidate.");
            break;
        }
        actuator();
    }
}

void main_redo(void)
{
    debug_message("redo()");
    if (undo_history_position < undo_history_length) {
        undo_history_position++;
        printf("undo_history_position = %d\n", undo_history_position);
        printf("undo_history_length = %d\n", undo_history_length);
        memcpy(&action, undo_history+undo_history_position, sizeof(action_call));
        actuator();
    }
}

void settings_actuator(void)
{
    
}

void actuator(void)
{
    undo_history_position++;
    /* an action has been taken, we are at the current head of the stack */
    undo_history_length = undo_history_position;
    memcpy(undo_history+undo_history_position, &action, sizeof(action_call));
    switch (action.id) {
    case ACTION_donothing:
        doNothing();
        break;
        /*
    case ACTION_new:
        _mainWin->newFile();
        break;
    case ACTION_open:
        _mainWin->openFile();
        break;
    case ACTION_save:
        _mainWin->savefile();
        break;
    case ACTION_print:
        _mainWin->print();
        break;
    case ACTION_designdetails:
        _mainWin->designDetails();
        break;
    case ACTION_exit:
        exit(0);
        break;
    case ACTION_cut:
        _mainWin->cut();
        break;
    case ACTION_icon16:
        debug_message("icon16()");
        _mainWin->iconResize(16);
        break;
    case ACTION_icon24:
        debug_message("icon24()");
        _mainWin->iconResize(24);
        break;
    case ACTION_icon32:
        debug_message("icon32()");
        _mainWin->iconResize(32);
        break;
    case ACTION_icon48:
        debug_message("icon48()");
        _mainWin->iconResize(48);
        break;
    case ACTION_icon64:
        debug_message("icon64()");
        _mainWin->iconResize(64);
        break;
    case ACTION_icon128:
        debug_message("icon128()");
        _mainWin->iconResize(128);
        break;
    case ACTION_settingsdialog:
        _mainWin->settingsDialog();
        break;
    case ACTION_undo:
        main_undo();
        break;
    case ACTION_redo:
        main_redo();
        break;
    case ACTION_makelayercurrent:
        makeLayerActive();
        break;
    case ACTION_layers:
        layerManager();
        break;
    case ACTION_layerprevious:
        layerPrevious();
        break;
    case ACTION_help:
        _mainWin->help();
        break;
    case ACTION_changelog:
        _mainWin->changelog();
        break;
    case ACTION_tipoftheday:
        _mainWin->tipOfTheDay();
        break;
    case ACTION_about:
        _mainWin->about();
        break;
    case ACTION_whatsthis:
        _mainWin->whatsThisContextHelp();
        break;
    case ACTION_zoomrealtime:
        zoomRealtime();
        break;
    case ACTION_zoomprevious:
        zoomPrevious();
        break;
    case ACTION_zoomwindow:
        zoomWindow();
        break;
    case ACTION_zoomdynamic:
        zoomDynamic();
        break;
    case ACTION_zoomscale:
        zoomScale();
        break;
    case ACTION_zoomcenter:
        zoomCenter();
        break;
    case ACTION_zoomin:
        zoomIn();
        break;
    case ACTION_zoomout:
        zoomOut();
        break;
    case ACTION_zoomselected:
        zoomSelected();
        break;
    case ACTION_zoomall:
        zoomAll();
        break;
    case ACTION_zoomextents:
        zoomExtents();
        break;
    case ACTION_panrealtime:
        panrealtime();
        break;
    case ACTION_panpoint:
        panpoint();
        break;
    case ACTION_panleft:
        panLeft();
        break;
    case ACTION_panright:
        panRight();
        break;
    case ACTION_panup:
        panUp();
        break;
    case ACTION_pandown:
        panDown();
        break;
    case ACTION_day:
        dayVision();
        break;
    case ACTION_night:
        nightVision();
        break;
    case ACTION_textbold:
        settings.text_style_bold = !settings.text_style_bold;
        break;
    case ACTION_textstrikeout:
        settings.text_style_strikeout = !settings.text_style_strikeout;
        break;
    case ACTION_textunderline:
        settings.text_style_underline = !settings.text_style_underline;
        break;
    case ACTION_textitalic:
        settings.text_style_italic = !settings.text_style_italic;
        break;
    case ACTION_textoverline:
        settings.text_style_overline = !settings.text_style_overline;
        break;
        */
    default:
        debug_message("Unrecognised action index.");
        debug_message("Action has not been implimented.");
        break;
    }
}

