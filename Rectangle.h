#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>
#include "Shape.h"
using std::vector;

class RectangleFactory; // Forward declaration

class Rectangle : public Shape {

friend class RectangleFactory;

private:
    Rectangle(int length, int width, const string& colour, int position_x, int position_y);
    Rectangle(const Rectangle& copy);

public:
    Shape* clone() override;
    ~Rectangle() override;
    vector<vector<char>> draw() override;
};

#endif
