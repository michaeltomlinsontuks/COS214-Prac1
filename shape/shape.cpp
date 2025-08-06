#include "Shape.h"

string to_string(const Shape *shape)
{
    string output = "";
    output += "Length: " + std::to_string(shape->length) + "\n";
    output += "Width: " + std::to_string(shape->width) + "\n";
    output += "Position X: " + std::to_string(shape->getPositionX()) + "\n";
    output += "Position Y: " + std::to_string(shape->getPositionY()) + "\n";
    output += "Colour: " + std::to_string(shape->getPositionX()) + "\n";

    return output;
}

bool Shape::operator==(Shape &copy)
{

    std::cout << "Checking length \t" << length << " =\t" << (copy.length == length) << std::endl;
    std::cout << "checking width  \t" << width << " =\t" << (copy.width == width) << std::endl;
    std::cout << "checking position_x \t" << position_x << " =\t" << (copy.position_x == position_x) << std::endl;
    std::cout << "checking position_y \t" << position_y << " =\t" << (copy.position_y == position_y) << std::endl;
    std::cout << "checking colour \t" << colour <<" "<< CRESET << " =\t" << (copy.colour == colour) << std::endl;
    std::cout << std::endl;
    return (copy.length == length && copy.width == width && copy.position_x == position_x && copy.position_y == position_y && copy.colour == colour);
}