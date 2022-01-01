/* This file is part of Embroidermodder 2.
 * ------------------------------------------------------------
 * Copyright 2021 The Embroidermodder Team
 * Embroidermodder 2 is Open Source Software.
 * See LICENSE.txt for licensing terms.
 * ------------------------------------------------------------
 * This file is for the in-progress translation of the action
 * system into C without dependencies.
 */

#include "embroidermodder.h"

#include <stdlib.h>

extern settings_wrapper settings;

void settings_actuator(int action)
{
    
}

void actuator(int action)
{
    switch (action) {
    case ACTION_donothing:
        _mainWin->doNothing();
        break;
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
        _mainWin->undo();
        break;
    case ACTION_redo:
        _mainWin->redo();
        break;
    case ACTION_makelayercurrent:
        _mainWin->makeLayerActive();
        break;
    case ACTION_layers:
        _mainWin->layerManager();
        break;
    case ACTION_layerprevious:
        _mainWin->layerPrevious();
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
        _mainWin->zoomRealtime();
        break;
    case ACTION_zoomprevious:
        _mainWin->zoomPrevious();
        break;
    case ACTION_zoomwindow:
        _mainWin->zoomWindow();
        break;
    case ACTION_zoomdynamic:
        _mainWin->zoomDynamic();
        break;
    case ACTION_zoomscale:
        _mainWin->zoomScale();
        break;
    case ACTION_zoomcenter:
        _mainWin->zoomCenter();
        break;
    case ACTION_zoomin:
        _mainWin->zoomIn();
        break;
    case ACTION_zoomout:
        _mainWin->zoomOut();
        break;
    case ACTION_zoomselected:
        _mainWin->zoomSelected();
        break;
    case ACTION_zoomall:
        _mainWin->zoomAll();
        break;
    case ACTION_zoomextents:
        _mainWin->zoomExtents();
        break;
    case ACTION_panrealtime:
        _mainWin->panrealtime();
        break;
    case ACTION_panpoint:
        _mainWin->panpoint();
        break;
    case ACTION_panleft:
        _mainWin->panLeft();
        break;
    case ACTION_panright:
        _mainWin->panRight();
        break;
    case ACTION_panup:
        _mainWin->panUp();
        break;
    case ACTION_pandown:
        _mainWin->panDown();
        break;
    case ACTION_day:
        dayVision();
        break;
    case ACTION_night:
        _mainWin->nightVision();
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
    default:
        debug_message("Unrecognised action index.");
        debug_message("Action has not been implimented.");
        break;
    }
}

