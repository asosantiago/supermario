#ifndef COMMON_LAYER_H
#define COMMON_LAYER_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "Layer.h"

using namespace std;

class CommonLayer : public Layer {
protected:
    virtual void update_position();
    virtual void render();
    virtual void reset();
public:
    CommonLayer(Position p, double layer_acceleration, string image_path);
    CommonLayer() {};
    virtual ~CommonLayer() {};
};

#endif // COMMON_LAYER_H
