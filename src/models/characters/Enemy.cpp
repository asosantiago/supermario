#include "Enemy.h"
#include <vector>

Enemy::Enemy(Position position, std::string name, std::string image_path, std::string image_flipped_path) : SpaceShip(position, name, image_path) {
    this->backwards = (position.get_position()[0] < 0);
    std::string use_image_path = image_path;
    if (backwards) {
        use_image_path = image_flipped_path;
        Logger::getInstance().logDebug("Enemy: new enemy using flipped image.");
    }else{
        Logger::getInstance().logDebug("Enemy: new enemy using normal image.");
    }
    this->element_surface = Renderer::getInstance().createNewSurface(use_image_path);
};

void Enemy::update() {
    float x = this->position.get_position()[0];
    if ((!this->backwards && x < -120) || (this->backwards && x > SCREEN_WIDTH + 120))
        return;
    update_position();
    render();
    // Check collisions
}

void Enemy::render() {
    std::vector<double> pos = this->position.get_position();
    Renderer::getInstance().setSurfaceElement(pos[0], pos[1], element_surface);
}

void Enemy::update_position() {
    float accel = SimpleConfig::getInstance().getEnemiesAcceleration();
    if (backwards) accel *= -1;
    position.move(accel, 0);
}

int Enemy::getRightLimit() {
    return this->position.get_position()[0] + this->element_surface->w;
}

int Enemy::getLeftLimit() {
    return this->position.get_position()[0];
}

int Enemy::getDownLimit() {
    return this->position.get_position()[1] + this->element_surface->h;
}

int Enemy::getUpLimit() {
    return this->position.get_position()[1];
}
