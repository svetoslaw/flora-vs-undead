#include "SDL.h"
#include <string>

static const std::string WINDOW_NAME = "Flora vs. Undead";
static const int WINDOW_WIDTH = 1280;
static const int WINDOW_HEIGHT = 720;

static const int GAME_FONT_SIZE = 18;

static const std::string PLAYER_NAME = "Gosho";

static const std::string MAIN_MENU_BACKGROUND_ID = "mainmenu";
static const SDL_Rect BACKGROUND_POSITION = { 0, 0, 1280, 720 };

static const std::string PLAY_BUTTON_ID = "playbutton";
static const SDL_Rect PLAY_BUTTON_POSITION = { 100, 570, 400, 100 };

static const std::string EXIT_BUTTON_ID = "exitbutton";
static const SDL_Rect EXIT_BUTTON_POSITION = { 780, 570, 400, 100 };

static const std::string SUNLIGHT_LABEL_ID = "sunlightlabel";
static const SDL_Rect SUNLIGHT_LABEL_POSITION = { 100, 100, 100, 50 };

static const SDL_Color SOLID_BLACK = { 0, 0, 0, 255 };
static const SDL_Color CYAN = { 0, 255, 255, 255 };

static const int UPDATE_INTERVAL_MILLIS = 3000;