#ifndef STAGE_DATA_H
#define STAGE_DATA_H

#include <vector>
#include <string>
#include "EnemyData.h"
#include "BackgroundData.h"
#include "PositionData.h"

using namespace std;

class StageData {
    public:
        StageData(string name, int stage_length, vector<EnemyData> enemies, vector<BackgroundData> backgrounds): name(name), stage_length(stage_length), enemies(enemies), backgrounds(backgrounds) {};
        string name;
        int stage_length;
        vector<EnemyData> enemies;
        vector<BackgroundData> backgrounds;
};

#endif // STAGE_DATA_H
