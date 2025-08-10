#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class SquareFactory; // Forward declaration

class Square : public Shape {

friend class SquareFactory;
friend void prototypeTesting();

private:
    Square(int length, int width, const std::string& colour, int position_x, int position_y);
    Square(const Square& copy);

public:
    Shape* clone() override;
    ~Square() override;
    std::vector<std::vector<CanvasCell>> draw() override;
};

#endif
