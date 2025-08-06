#include "Rectangle.h"

Shape* Rectangle::clone() {
    Logger::getInstance()->info("Rectangle cloned with values: length = " + std::to_string(this->length) + ", width = " + std::to_string(this->width) + ", colour = " + this->colour + ", position_x = " + std::to_string(this->position_x) + ", position_y = " + std::to_string(this->position_y));
    return new Rectangle(*this);
}

Rectangle::Rectangle(int length, int width, const string& colour, int position_x, int position_y)
    : Shape(length, width, colour, position_x, position_y) {
    Logger::getInstance()->info("Rectangle created with values: length = " + std::to_string(length) + ", width = " + std::to_string(width) + ", colour = " + colour + ", position_x = " + std::to_string(position_x) + ", position_y = " + std::to_string(position_y));
}

Rectangle::Rectangle(const Shape* copy)
    : Shape(copy) {
    Logger::getInstance()->info("Rectangle copied with values: length = " + std::to_string(copy.length) + ", width = " + std::to_string(copy.width) + ", colour = " + copy.colour + ", position_x = " + std::to_string(copy.position_x) + ", position_y = " + std::to_string(copy.position_y));
}

Rectangle::~Rectangle() {
    // Default destructor
}

vector<vector<CanvasCell>> Rectangle::draw() {
    Logger::getInstance()->info("Rectangle drawn with values: length = " + std::to_string(this->length) + ", width = " + std::to_string(this->width) + ", colour = " + this->colour + ", position_x = " + std::to_string(this->position_x) + ", position_y = " + std::to_string(this->position_y));
    vector<vector<CanvasCell>> result;
    result.resize(length, vector<CanvasCell>(width, CanvasCell(colour, ' ')));
    return result;
}
