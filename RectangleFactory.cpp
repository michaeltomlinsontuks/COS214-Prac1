#include "RectangleFactory.h"

Shape* RectangleFactory::createShape(int length, int width, const std::string& colour, int position_x, int position_y) {
    return new Rectangle(length, width, colour, position_x, position_y);
}

std::string RectangleFactory::toString() {
    return "RectangleFactory";
}
