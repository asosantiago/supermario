#include "Layer.h"

Layer::Layer(Position p, double layer_acceleration, string image_path) :
    GameObject(p),
    layer_acceleration(layer_acceleration),
    image_path(image_path) {
        this->element_surface = Renderer::getInstance().createNewSurface(image_path);
    }

void Layer::update() {
    this->update_position();
    this->render();

    if (this->out_of_bounds())
        this->reset();
}

bool Layer::out_of_bounds() {
    return this->position.get_position()[0] <= (this->element_surface->w) * -1;
}
