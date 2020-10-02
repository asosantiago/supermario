#ifndef LAYER_H
#define LAYER_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "../GameObject.h"

#include "../../services/Renderer.h"
#include "../Position.h"

using namespace std;

class Layer : public GameObject {
protected:
    double layer_acceleration;
    SDL_Surface* element_surface = 0;
    virtual void update_position() = 0;
    virtual void render() = 0;
    virtual void reset() = 0;
    bool out_of_bounds();
public:
    string image_path;
    Layer(Position p, double layer_acceleration, string image_path);
    Layer() {};
    virtual void update();
    virtual ~Layer() {};
};

#endif // LAYER_H
