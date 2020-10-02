#include "Character.h"
#include <vector>

Character::Character(Position position, std::string name, std::string image_path) : SpaceShip(position, name, image_path) {
    this->element_surface = Renderer::getInstance().createNewSurface(image_path);

};

void Character::update() {
    update_position();
    render();
    // Check collisionss
}

void Character::render() {
    std::vector<double> pos = this->position.get_position();
    Renderer::getInstance().setSurfaceElement(pos[0], pos[1], element_surface);
}

void Character::update_position() {
    std::vector<bool> keys_held = InputComponent::getInstance().get_user_input();
    float accel = SimpleConfig::getInstance().getPlayerAcceleration();
    double x_offset = (keys_held[RIGHT] * accel) - (keys_held[LEFT] * accel);
    double y_offset = (keys_held[DOWN] * accel) - (keys_held[UP] * accel);

    std::vector<double> pos = this->position.get_position();

    int w = this->element_surface->w;
    int h = this->element_surface->h;

    if ((pos[0] + x_offset) >= 0 && (pos[0] + x_offset) <= SCREEN_WIDTH - w) position.move(x_offset, 0);
    if ((pos[1] + y_offset) >= 0 && (pos[1] + y_offset) <= SCREEN_HEIGHT - h) position.move(0, y_offset);
    
}
