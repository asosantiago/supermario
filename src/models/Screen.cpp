#include "Screen.h"
#include <iostream>
#include <SDL2/SDL_image.h>

using namespace std;

SDL_Surface base_surface;

// Screen::Screen(int height, int width, string title) : height(height), width(width), title(title)) {}
bool Screen::init(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        //fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
        Logger::getInstance().logError("Screen: could not initialize sdl2: " + string(SDL_GetError()));
        return false;
    }else{
        Logger::getInstance().logInfo("Screen: sdl2 video initialized");
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        //fprintf(stderr, "could not initialize sdl2_image: %s\n", IMG_GetError());
        Logger::getInstance().logError("Screen: could not initialize sdl2_image: " + string(IMG_GetError()));
        return false;
    }else{
        Logger::getInstance().logInfo("Screen: sdl2 image initialized");
    }
    window = SDL_CreateWindow(
                "Glaylancer",
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH, SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN
                );
    if (window == NULL) {
        //fprintf(stderr, "could not create window: %s\n", SDL_GetError());
        Logger::getInstance().logError("Screen: could not create window: " + string(SDL_GetError()));
        return false;
    }else{
        Logger::getInstance().logInfo("Screen: sdl2 window created");
    }
    this->load_icon();
    screenSurface = SDL_GetWindowSurface(window);
    if (screenSurface == NULL) {
        //fprintf(stderr, "could not get window: %s\n", SDL_GetError());
        Logger::getInstance().logError("Screen: could not get window: " + string(SDL_GetError()));
        return false;
    }else{
        Logger::getInstance().logInfo("Screen: sdl2 screenSurface ok");
    }
    initialized = true;
    Logger::getInstance().logInfo("Screen: Game initialized");
    return true;
};

SDL_Surface* Screen::create_surface(string filename) {
    SDL_Surface* img = IMG_Load(filename.c_str());
    if (img == NULL) {
        //fprintf(stderr, "could not load image: %s - %s\n", IMG_GetError(), filename.c_str());
        Logger::getInstance().logError("Screen: could not load image: " + string(IMG_GetError())+ " - "+ + " - " + filename.c_str());
        return NULL;
    }
    SDL_Surface* optimizedImg = SDL_ConvertSurface(img, screenSurface->format, 0);
    if (optimizedImg == NULL) Logger::getInstance().logError("Screen: could not optimize image: " + string(SDL_GetError())); //fprintf(stderr, "could not optimize image: %s\n", SDL_GetError());
    SDL_FreeSurface(img);
    return optimizedImg;
}

void Screen::load_icon() {
    string f = "src/images/window_icon.png";
    SDL_Surface* icon = IMG_Load(f.c_str());
    if (filesystem::exists(f) && icon != NULL) {
        SDL_SetWindowIcon(this->window, icon);
    }
}

void Screen::add_surface_to_screen(int x, int y, SDL_Surface* element_surface) {
    apply_surface(x, y, element_surface, screenSurface);
}

void Screen::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, clip, destination, &offset );
    // fprintf(stderr, "blip blop: %s\n", SDL_GetError());
    //Logger::getInstance().logError("Screen: blip blop: " + string(SDL_GetError()));
}

void Screen::refresh_screen() {
    SDL_UpdateWindowSurface(window);
}

bool Screen::isInitialized(){
    return initialized;
};

void Screen::set_delay(int mseg){
    SDL_Delay(mseg);
}

void Screen::close(){
    SDL_DestroyWindow(window);
    SDL_Quit();
};

void Screen::free(SDL_Surface* sdl_surface) {
    SDL_FreeSurface(sdl_surface);
}
