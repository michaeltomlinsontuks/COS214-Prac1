#include "Rectangle.h"

Shape* Rectangle::clone() {
    Logger::getInstance()->info("Rectangle cloned with values: length = " + std::to_string(this->getLength()) + ", width = " + std::to_string(this->getWidth()) + ", colour = " + this->getColour() + ", position_x = " + std::to_string(this->getPositionX()) + ", position_y = " + std::to_string(this->getPositionY()));
    return new Rectangle(*this);}

Rectangle::Rectangle(int length, int width, const std::string& colour, int position_x, int position_y)
    : Shape(length, width, colour, position_x, position_y) {
    Logger::getInstance()->info("Rectangle created with values: length = " + std::to_string(length) + ", width = " + std::to_string(width) + ", colour = " + colour + ", position_x = " + std::to_string(position_x) + ", position_y = " + std::to_string(position_y));
}

Rectangle::Rectangle(const Rectangle& copy)
    : Shape(copy) {
    Logger::getInstance()->info("Rectangle copied with values: length = " + std::to_string(copy.getLength()) + ", width = " + std::to_string(copy.getWidth()) + ", colour = " + copy.getColour() + ", position_x = " + std::to_string(copy.getPositionX()) + ", position_y = " + std::to_string(copy.getPositionY()));
}

Rectangle::~Rectangle() {
    // Default destructor
}

std::vector<std::vector<CanvasCell>> Rectangle::draw() {
    Logger::getInstance()->info("Rectangle drawn with values: length = " + std::to_string(this->getLength()) + ", width = " + std::to_string(this->getWidth()) + ", colour = " + this->getColour() + ", position_x = " + std::to_string(this->getPositionX()) + ", position_y = " + std::to_string(this->getPositionY()));
    std::vector<std::vector<CanvasCell>> result;
    result.resize(getLength(), vector<CanvasCell>(getWidth(), CanvasCell(getColour(), ' ')));
    return result;
}
