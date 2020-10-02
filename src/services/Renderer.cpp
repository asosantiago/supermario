#include "Renderer.h"

using namespace std;

bool Renderer::initScreen() {
    return Screen::getInstance().init();
}

SDL_Surface* Renderer::createNewSurface(string image_path) {
    return Screen::getInstance().create_surface(image_path);
}

void Renderer::setSurfaceElement(int x, int y, SDL_Surface* surface) {
    Screen::getInstance().add_surface_to_screen(x, y, surface);
}

void Renderer::refresh() {
    Screen::getInstance().refresh_screen();
}

void Renderer::free(SDL_Surface* sdl_surface) {
    Screen::getInstance().free(sdl_surface);
}

void Renderer::close() {
    Screen::getInstance().close();
}
