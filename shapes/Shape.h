#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <string>
#include "../loggerOCI//ANSI-color-codes.h"
#include "../loggerOCI//Logger.h"
#include "../canvas/CanvasCell.h"

using std::vector;
using std::string;

class Shape {
    friend string to_string(const Shape *);
//Apparently we need to use private and then use getters
private:
    int length;
    int width;
    string colour;
    int position_x;
    int position_y;

protected:
    Shape(int length = 0, int width = 0, const string& colour = "", int position_x = 0, int position_y = 0)
        : length(length), width(width), colour(colour), position_x(position_x), position_y(position_y) {}
    Shape(const Shape *copy)
        : length(copy->length), width(copy->width), colour(copy->colour), position_x(copy->position_x), position_y(copy->position_y) {}

public:
    bool operator==(Shape &copy);


public:
    int getLength() const { return length; }
    int getWidth() const { return width; }
    string getColour() const { return colour; }
    int getPositionX() const { return position_x; }
    int getPositionY() const { return position_y; }
    virtual Shape* clone() = 0;
    virtual vector<vector<CanvasCell>> draw() = 0;
    virtual ~Shape() {}
};

#endif
