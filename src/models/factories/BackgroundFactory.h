#ifndef BACKGROUND_FACTORY_H
#define BACKGROUND_FACTORY_H

#include <vector>
#include <string>
#include <filesystem>
#include "BackgroundData.h"
#include "../background/Background.h"
#include "../background/CommonLayer.h"
#include "../background/ContinuousLayer.h"
#include "../../common/logger/Logger.h"

using namespace std;

class BackgroundFactory {
    private:
        vector<BackgroundData> data;
    public:
        BackgroundFactory(vector<BackgroundData> data);
        Background build();
        ~BackgroundFactory() {};
};

#endif // BACKGROUND_FACTORY_H
