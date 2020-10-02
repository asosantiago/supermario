#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "SpaceShip.h"
#include "../../services/Renderer.h"
#include "../../components/InputComponent.h"
#include "../Position.h"

using namespace std;

class Character : public SpaceShip {
private:
    SDL_Surface* element_surface = 0;
    void update_position();
    void render();
public:
    Character(Position position, std::string name, std::string image_path);
    Character() {};
    virtual void update();
    ~Character() {};
};

#endif // CHARACTER_H