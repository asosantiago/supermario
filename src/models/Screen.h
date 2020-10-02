#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <filesystem>
#include "../common/logger/Logger.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

using namespace std;

class Screen {
    private:
        int height;
        int width;
        string title;
        bool initialized;
        Screen() {};
        ~Screen() {};
        void load_icon();
    public:
        string window_error;
        SDL_Window *window;
        SDL_Surface *screenSurface;
        void setSize (int height, int width);
        bool isInitialized();
        bool init();
        void close();
        void set_delay(int mseg);
        SDL_Surface* create_surface(string filename);
        void add_surface_to_screen(int x, int y, SDL_Surface* element_surface);
        void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL);
        void refresh_screen();
        void free(SDL_Surface* sdl_surface);
        // Screen(Screen const&);
        // void operator=(Screen const&);
        static Screen& getInstance() {
            static Screen instance;
            return instance;
        }
        // disable copy/move -- this is a Singleton
        Screen(const Screen&) = delete;
        Screen(Screen&&) = delete;
        Screen& operator=(const Screen&) = delete;
        Screen& operator=(Screen&&) = delete;
};

#endif // SCREEN_H
