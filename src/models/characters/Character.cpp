#include "Character.h"
#include <vector>

Character::Character(Position position, std::string name, std::string image_path) : SpaceShip(position, name, image_path) {
    this->element_surface = Renderer::getInstance().createNewSurface(image_path);
    this->y_vel = 0;
};

void Character::update() {
    update_position();
}

void Character::doUpdate() {
    do_update_position();
    render();
}

void Character::render() {
    std::vector<double> pos = this->position.get_position();
    Renderer::getInstance().setSurfaceElement(pos[0], pos[1], element_surface);
}

void Character::update_position() {
    std::vector<bool> keys_held = InputComponent::getInstance().get_user_input();
    float accel = SimpleConfig::getInstance().getPlayerAcceleration();
    float velInitY = SimpleConfig::getInstance().getVelInitY();
    float gravity = SimpleConfig::getInstance().getGravity();
    double x_offset = (keys_held[RIGHT] * accel) - (keys_held[LEFT] * accel);
    double y_offset = 0;
    std::vector<double> pos = this->position.get_position();
    this->futurePosition = Position(pos[0], pos[1]);

    if (pos[1] == SimpleConfig::getInstance().getFloorY()) {
        if (keys_held[UP]) {
            this->y_vel = - velInitY;
        }
    }

    this->y_vel += gravity;

    y_offset = this->y_vel;

    int w = this->element_surface->w;
    int h = this->element_surface->h;

    if ((pos[0] + x_offset) >= 0 && (pos[0] + x_offset) <= SCREEN_WIDTH - w) futurePosition.move(x_offset, 0);
    if ((pos[1] + y_offset) >= 0 && (pos[1] + y_offset) <= SimpleConfig::getInstance().getFloorY()) futurePosition.move(0, y_offset);
    if ((pos[1] + y_offset) > SimpleConfig::getInstance().getFloorY()) futurePosition.move(0, SimpleConfig::getInstance().getFloorY()-pos[1]);
}

void Character::do_update_position() {
    this->position.move_to_position(this->futurePosition);
}
