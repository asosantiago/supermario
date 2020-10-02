#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Position.h"
#include "../common/logger/Logger.h"
#include "../common/config/SimpleConfig.h"

class GameObject {
public:
    virtual void update() = 0;
    GameObject(Position position) : position(position) {};
    GameObject() {};
    virtual ~GameObject() {};
protected:
    Position position;
};

#endif // GAME_OBJECT_H
