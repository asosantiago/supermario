#ifndef POSITION_H
#define POSITION_H

#include <vector>
#include <string>

class Position {
    private:
        int x;
        int y;
    public:
        Position(int x, int y);
        Position(double x, double y);
        Position() {};
        void move(double x_offset, double y_offset);
        void move_to_position(Position position);
        const std::vector<double> get_position();
        const std::string print();
        bool operator==(const Position& other);
        ~Position();
};

#endif // POSITION_H
