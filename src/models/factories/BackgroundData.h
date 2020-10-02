#ifndef BACKGROUND_DATA_H
#define BACKGROUND_DATA_H

#include <vector>
#include <string>
#include "PositionData.h"

using namespace std;

class BackgroundData {
    public:
        BackgroundData(string path, string default_path, PositionData position, string type, float speed): path(path), default_path(default_path), position(position), type(type), speed(speed) {};
        string path;
        string default_path;
        PositionData position;
        string type;
        float speed;
};

#endif // BACKGROUND_DATA_H
