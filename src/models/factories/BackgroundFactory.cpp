#include "BackgroundFactory.h"

BackgroundFactory::BackgroundFactory(vector<BackgroundData> data) : data(data) {}

Background BackgroundFactory::build() {
    vector<shared_ptr<Layer>> layers;

    for (int i = 0; i < data.size(); i++) {
        string path = data[i].path;
        if (!filesystem::exists(path)) {
            Logger::getInstance().logError("BackgroundFactory: File: " + path + " does not exists, loading default");
            path = data[i].default_path;
        }
        if (data[i].type == "Common") {
            layers.push_back(make_shared<CommonLayer>(Position(data[i].position.x, data[i].position.y), data[i].speed, path));
            Logger::getInstance().logDebug("BackgroundFactory: New common layer.");
        }  
        if (data[i].type == "Continuous") {
            layers.push_back(make_shared<ContinuousLayer>(Position(data[i].position.x, data[i].position.y), data[i].speed, path));
            Logger::getInstance().logDebug("BackgroundFactory: New continuous layer.");
        } 
    }

    return Background(move(layers));
}
