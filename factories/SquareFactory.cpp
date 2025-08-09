#include "SquareFactory.h"

Shape* SquareFactory::createShape(int length, int width, const std::string& colour, int position_x, int position_y) {
    return new Square(length, width, colour, position_x, position_y);
}

void SquareFactory::toString() {
    // Example implementation
    // std::cout << "SquareFactory" << std::endl;
}

SquareFactory::SquareFactory(SquareFactory& copy) {
    (void)copy;
    // Copy constructor implementation if needed
}
