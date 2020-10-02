#include "SpaceShip.h"

SpaceShip::SpaceShip(Position position, std::string name, std::string image_path) : GameObject(position) {
    this->position = position;
    this->name = name;
    this->image_path = image_path;
};
