#include "EnemyFactory.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

EnemyFactory::EnemyFactory(vector<EnemyData> data, int stage_length) : data(data), stage_length(stage_length) {}

vector<shared_ptr<Enemy>> EnemyFactory::build() {
    vector<shared_ptr<Enemy>> enemies;

    int minHeight = 0;
    int maxHeight =  SCREEN_HEIGHT - 100;

    int minWidth = (stage_length / 2);
    int maxWidth = stage_length * SCREEN_WIDTH;

    for (int i = 0 ; i < data.size() ; i++) {
        string type = data[i].type;
        string image = data[i].image;
        string image_flipped = data[i].image_flipped;
        
        if (!filesystem::exists(image)) {
            Logger::getInstance().logError("EnemyFactory: File: " + image +  " does not exists, loading default");
            image = data[i].default_image;
        }

        if (!filesystem::exists(image_flipped)) {
            Logger::getInstance().logError("EnemyFactory: File: " + image + " does not exists, loading default");
            image_flipped = data[i].default_image;
        }

        for (int j = 0 ; j < data[i].amount - 1 ; j++) {

            int positionX = minWidth + ( std::rand() % ( maxWidth - minWidth + 1 ) );
            // int positionY = minHeight + ( std::rand() % ( maxHeight - minHeight + 1 ) );
            int positionY = SimpleConfig::getInstance().getFloorY() + 45;
            
            Position position = Position(positionX, positionY);

            enemies.push_back(make_shared<Enemy>(position, type, image, image_flipped));
        }
    }

    return enemies;
}
