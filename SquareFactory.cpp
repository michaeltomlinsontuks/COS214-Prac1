#include "SquareFactory.h"

Shape *SquareFactory::createShape(int length, int width, const std::string &colour, int position_x, int position_y)
{
    return new Square(length, width, colour, position_x, position_y);
}

std::string SquareFactory::toString()
{
    return "SquareFactory";
}
