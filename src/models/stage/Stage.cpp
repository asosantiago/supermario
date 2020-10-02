#include "Stage.h"

Stage::Stage(string name, int stage_length, vector<shared_ptr<Enemy>> enemies, Background background) :
    GameObject(Position(0,0)), name(name), stage_length(stage_length), enemies(move(enemies)), background(background) {}


void Stage::update() {
    this->update_position();
    // this->render();
}

void Stage::update_position() {
    this->background.update();
    this->update_enemies();

    this->position.move(STAGE_ACCELERATION, 0);
}

void Stage::render() {}

void Stage::update_enemies() {
    for (int i = 0; i < this->enemies.size(); i++) {
        this->enemies[i]->update();
    }
}

bool Stage::is_finished() {
    int pos_x = this->position.get_position()[0];
    // TODO: Check that there are no more enemies in the screen
    return pos_x >= this->stage_length * SCREEN_WIDTH;
}

string Stage::get_name() {
    return this->name;
}

vector<shared_ptr<Enemy>> Stage::getEnemies() {
    return this->enemies;
}
