#ifndef ENEMY_H
#define ENEMY_H

#include <string>

#include "SpaceShip.h"
#include "../../services/Renderer.h"
#include "../Position.h"

class Enemy : public SpaceShip {
    private:
        SDL_Surface* element_surface = 0;
        void update_position();
        void render();
        bool backwards;
    public:
        Enemy(Position position, std::string name, std::string image_path, std::string image_flipped_path);
        Enemy() {};
        virtual void update();
        ~Enemy() {};
        int getRightLimit();
        int getLeftLimit();
        int getDownLimit();
        int getUpLimit();
};

#endif // ENEMY_H