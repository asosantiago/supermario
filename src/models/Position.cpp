#include "Position.h"

Position::Position(int x, int y) : x(x * 100), y(y * 100) {}
Position::Position(double x, double y) : x(x * 100), y(y * 100) {}

void Position::move(double x_offset, double y_offset) {
    // TODO add some kind of validation
    this->x += (x_offset * 100);
    this->y += (y_offset * 100);
}

void Position::move_to_position(Position position) {
    this->x = position.x;
    this->y = position.y;
}

const std::vector<double> Position::get_position() {
    std::vector<double> position(2, 0);
    position[0] = this->x / 100.0;
    position[1] = this->y / 100.0;

    return position;
}

const std::string Position::print() {
   std::vector<double> pos = this->get_position();
   return "{x: " + std::to_string(pos[0]) + ", y: " + std::to_string(pos[1]) + "}";
}

bool Position::operator==(const Position& other) {
    return (this->x == other.x && this->y == other.y);
}

Position::~Position() {};
