#include "CommonLayer.h"

CommonLayer::CommonLayer(Position p, double layer_acceleration, string image_path) :
    Layer(p, layer_acceleration, image_path) {}

void CommonLayer::render() {
    std::vector<double> pos = this->position.get_position();
    Renderer::getInstance().setSurfaceElement(pos[0], pos[1], element_surface);
}

void CommonLayer::update_position() {
    position.move(SimpleConfig::getInstance().getGameAcceleration() * layer_acceleration, 0);
}

void CommonLayer::reset() {
    // TODO: Hacer que aparezca en algún lugar random
    this->position.move(this->element_surface->w * 2, 0);
}
