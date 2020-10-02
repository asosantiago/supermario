#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "../models/Screen.h"

class Renderer {
    private:
        Renderer() {};
        ~Renderer() {};
    public:
        bool initialized;
        bool initScreen();
        SDL_Surface* createNewSurface(string imagePath);
        void setSurfaceElement(int x, int y, SDL_Surface* surface);
        void free(SDL_Surface* sdl_surface);
        void refresh();
        void close();
        // Renderer(Renderer const&);
        // void operator=(Renderer const&);
        static Renderer& getInstance() {
            static Renderer instance;
            return instance;
        }
        Renderer(const Renderer&) = delete;
        Renderer(Renderer&&) = delete;
        Renderer& operator=(const Renderer&) = delete;
        Renderer& operator=(Renderer&&) = delete;
};

#endif // RENDERER_H
