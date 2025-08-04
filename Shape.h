#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <string>
#include "ANSI-color-codes.h"
#include "Logger.h"
using std::vector;
using std::string;

class Shape {
//Changed this to protected because I can't do the Shape-based functions without these fields
protected:
    int length;
    int width;
    string colour;
    int position_x;
    int position_y;
    Shape(int length = 0, int width = 0, const string& colour = "", int position_x = 0, int position_y = 0)
        : length(length), width(width), colour(colour), position_x(position_x), position_y(position_y) {}

public:
    virtual Shape* clone() = 0;
    virtual vector<vector<char>> draw() = 0;
    virtual ~Shape() {}
};

#endif
