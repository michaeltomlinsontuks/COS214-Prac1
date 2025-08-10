#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class RectangleFactory; // Forward declaration

class Rectangle : public Shape {

friend class RectangleFactory;
friend void prototypeTesting();

private:
    Rectangle(int length, int width, const std::string& colour, int position_x, int position_y);
    Rectangle(const Rectangle& copy);

public:
    Shape* clone() override;
    ~Rectangle() override;
    std::vector<std::vector<CanvasCell>> draw() override;
};

#endif
