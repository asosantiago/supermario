#ifndef CONTINUOUS_LAYER_H
#define CONTINUOUS_LAYER_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "Layer.h"
#include "CommonLayer.h"

using namespace std;

class ContinuousLayer : public Layer {
private:
    vector<CommonLayer> layers;
protected:
    virtual void update_position();
    virtual void render();
    virtual void reset();
public:
    ContinuousLayer(Position p, double layer_acceleration, string image_path);
    ContinuousLayer() {};
    virtual ~ContinuousLayer() {};
};

#endif // CONTINUOUS_LAYER_H
