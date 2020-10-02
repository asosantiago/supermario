#include "Background.h"
#include <vector>

Background::Background(vector<shared_ptr<Layer>> layers) : GameObject(Position(0,0)), layers(move(layers)) {};

void Background::update() {
    for (int i = 0; i < this->layers.size(); i++) {
        layers[i]->update();
    }
}
void Background::render() {}
void Background::update_position() {}

Background::~Background() {
    this->layers.clear();
}
