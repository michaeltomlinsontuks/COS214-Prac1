#include "Square.h"

Shape* Square::clone() {
    Logger::getInstance()->info("Square cloned with values: length = " + std::to_string(this->length) + ", width = " + std::to_string(this->width) + ", colour = " + this->colour + ", position_x = " + std::to_string(this->position_x) + ", position_y = " + std::to_string(this->position_y));
    return new Square(*this);
}

Square::Square(int length, int width, const string& colour, int position_x, int position_y)
    : Shape(length, width, colour, position_x, position_y) {
    Logger::getInstance()->info("Square created with values: length = " + std::to_string(length) + ", width = " + std::to_string(width) + ", colour = " + colour + ", position_x = " + std::to_string(position_x) + ", position_y = " + std::to_string(position_y));
}

Square::Square(const Square& copy)
    : Shape(copy) {
    Logger::getInstance()->info("Square copied with values: length = " + std::to_string(copy.length) + ", width = " + std::to_string(copy.width) + ", colour = " + copy.colour + ", position_x = " + std::to_string(copy.position_x) + ", position_y = " + std::to_string(copy.position_y));
}

Square::~Square() {
    // Default destructor
}

vector<vector<char>> Square::draw() {
    throw "Square::draw - Not yet implemented";
}
