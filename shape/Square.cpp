#include "Square.h"

Shape* Square::clone() {
    Logger::getInstance()->info("Square cloned with values: length = " + std::to_string(this->getLength()) + ", width = " + std::to_string(this->getWidth()) + ", colour = " + this->getColour() + ", position_x = " + std::to_string(this->getPositionX()) + ", position_y = " + std::to_string(this->getPositionY()));
    return new Square(*this);}

Square::Square(int length, int width, const string& colour, int position_x, int position_y)
    : Shape(length, width, colour, position_x, position_y) {
    Logger::getInstance()->info("Square created with values: length = " + std::to_string(length) + ", width = " + std::to_string(width) + ", colour = " + colour + ", position_x = " + std::to_string(position_x) + ", position_y = " + std::to_string(position_y));
}

Square::Square(const Square& copy)
    : Shape(copy) {
    Logger::getInstance()->info("Square copied with values: length = " + std::to_string(copy.getLength()) + ", width = " + std::to_string(copy.getWidth()) + ", colour = " + copy.getColour() + ", position_x = " + std::to_string(copy.getPositionX()) + ", position_y = " + std::to_string(copy.getPositionY()));
}

Square::~Square() {
    // Default destructor
}

vector<vector<CanvasCell>> Square::draw() {
    Logger::getInstance()->info("Square drawn with values: length = " + std::to_string(this->getLength()) + ", width = " + std::to_string(this->getWidth()) + ", colour = " + this->getColour() + ", position_x = " + std::to_string(this->getPositionX()) + ", position_y = " + std::to_string(this->getPositionY()));
    vector<vector<CanvasCell>> result;
    result.resize(getLength(), vector<CanvasCell>(getWidth(), CanvasCell(getColour(), ' ')));
    return result;
}
