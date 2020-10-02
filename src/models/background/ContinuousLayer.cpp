#include "ContinuousLayer.h"

ContinuousLayer::ContinuousLayer(Position p, double layer_acceleration, string image_path) :
    Layer(p, layer_acceleration, image_path) {
        CommonLayer c1 = CommonLayer(p, layer_acceleration, image_path);
        Position p2 = p;
        p2.move(element_surface->w, 0);
        CommonLayer c2 = CommonLayer(p2, layer_acceleration, image_path);

        layers.push_back(c1);
        layers.push_back(c2);
    }

void ContinuousLayer::render() {
    for (int i = 0; i < layers.size(); i++)
        layers[i].update();
}

void ContinuousLayer::update_position() {
    position.move(SimpleConfig::getInstance().getGameAcceleration() * layer_acceleration, 0);
}

void ContinuousLayer::reset() {
    this->position.move(this->element_surface->w * 2, 0);
}
