#ifndef STAGE_H
#define STAGE_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "../characters/Character.h"
#include "../characters/Enemy.h"
#include "../background/Background.h"
#include "../Screen.h"

#define STAGE_ACCELERATION 1

using namespace std;

class Stage : public GameObject {
private:
    string name;
    int stage_length;
    vector<shared_ptr<Enemy>> enemies;
    Background background;
    void update_position();
    void update_enemies();
    void render();
public:
    Stage(string name, int stage_length, vector<shared_ptr<Enemy>> enemies, Background background);
    Stage() {};
    virtual void update();
    bool is_finished();
    string get_name();
    ~Stage() {};
    string getName();
    vector<shared_ptr<Enemy>> getEnemies();
};


#endif // STAGE_H
