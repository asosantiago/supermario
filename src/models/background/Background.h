#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <memory>
#include "Layer.h"

using namespace std;

class Background : public GameObject {
private:
    vector<shared_ptr<Layer>> layers;
    void update_position();
    void render();
public:
    Background(vector<shared_ptr<Layer>> layers);
    Background() {};
    virtual void update();
    ~Background();
};


#endif // BACKGROUND_H
