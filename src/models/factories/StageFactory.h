#ifndef STAGE_FACTORY_H
#define STAGE_FACTORY_H

#include <vector>
#include <string>
#include <filesystem>

#include "../stage/Stage.h"
#include "StageData.h"
#include "EnemyFactory.h"
#include "BackgroundFactory.h"

using namespace std;

class StageFactory {
    private:
        StageData stage_data;
    public:
        StageFactory(StageData stage_data);
        Stage build();
        ~StageFactory() {};
};

#endif // STAGE_FACTORY_H
