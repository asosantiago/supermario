#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

#include <string>
#include <sstream>
#include <iostream>

#include "../GameObject.h"

class SpaceShip : public GameObject{
    public:
        std::string name;
        std::string image_path;
        SpaceShip(Position position, std::string name, std::string image_path);
        SpaceShip() {};
        virtual ~SpaceShip() {};
    private:
};

#endif // SPACE_SHIP_H
