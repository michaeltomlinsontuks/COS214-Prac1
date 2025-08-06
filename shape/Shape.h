#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <string>
#include "../loggerOCI/ANSI-color-codes.h"
#include "../loggerOCI/Logger.h"
#include "../loggerOCI/CanvasCell.h"

using std::string;
using std::vector;

class Shape
{
    // Changed this to protected because I can't do the Shape-based functions without these fields

    // remove this when getters added
    friend string to_string(const Shape *);

protected:
    int length;
    int width;
    string colour;
    int position_x;
    int position_y;
    Shape(int length = 0, int width = 0, const string &colour = "", int position_x = 0, int position_y = 0)
        : length(length), width(width), colour(colour), position_x(position_x), position_y(position_y) {}

    // add to diagram
    Shape(Shape *copy)
        : length(copy->length), width(copy->width), colour(copy->colour), position_x(copy->position_x), position_y(copy->position_y) {}

    bool operator==(Shape *copy)
    {
        return (copy->length == length && copy->width == width && copy->position_x == position_x && copy->position_y == position_y && copy->colour == colour);
    }

public:
    int getPositionX() const { return position_x; }
    int getPositionY() const { return position_y; }
    virtual Shape *clone() = 0;
    virtual vector<vector<CanvasCell>> draw() = 0;
    virtual ~Shape() {}
};

// change with the getters
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
// change with the getters

#endif
