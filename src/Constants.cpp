#include "SDL.h"
#include <string>

static const int GAME_FONT_SIZE = 18;

static const std::string MAIN_MENU_BACKGROUND_ID = "mainmenu";
static const std::string PLAY_BUTTON_ID = "playbutton";
static const std::string EXIT_BUTTON_ID = "exitbutton";
static const std::string SUNLIGHT_LABEL_ID = "sunlightlabel";

static const SDL_Color SOLID_BLACK = { 0, 0, 0, 255 };
static const SDL_Color CYAN = { 0, 255, 255, 255 };

static const int UPDATE_INTERVAL_MILLIS = 1000;