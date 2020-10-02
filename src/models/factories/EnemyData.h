#ifndef ENEMY_DATA_H
#define ENEMY_DATA_H

#include <string>
#include <filesystem>

using namespace std;

class EnemyData {
    public:
        EnemyData(string image, string image_flipped, string default_image, int amount, string type): image(image), image_flipped(image_flipped), default_image(default_image), amount(amount), type(type) {};
        string image;
        string image_flipped;
        string default_image;
        int amount;
        string type;
};

#endif // ENEMY_DATA_H
