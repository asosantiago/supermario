#include "StageFactory.h"

StageFactory::StageFactory(StageData stage_data) : stage_data(stage_data){}

Stage StageFactory::build() {
    Background background = BackgroundFactory(stage_data.backgrounds).build();
    vector<shared_ptr<Enemy>> enemies = EnemyFactory(stage_data.enemies, stage_data.stage_length).build();
    Logger::getInstance().logInfo("StageFactory: create stage");
    return Stage(stage_data.name, stage_data.stage_length, enemies, background);
}
