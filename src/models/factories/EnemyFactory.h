#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H

#include <vector>
#include <string>
#include <filesystem>
#include "EnemyData.h"
#include "../characters/Enemy.h"
#include "../../common/logger/Logger.h"

using namespace std;

class EnemyFactory {
    private:
        vector<EnemyData> data;
        int stage_length;
    public:
        EnemyFactory(vector<EnemyData> data, int stage_length);
        vector<shared_ptr<Enemy>> build();
        ~EnemyFactory() {};
};

#endif // ENEMY_FACTORY_H
