#ifndef SQUARE_H
#define SQUARE_H

#include <vector>
#include "Shape.h"
#include "CanvasCell.h"
using std::vector;

class SquareFactory; // Forward declaration

class Square : public Shape {

friend class SquareFactory;

private:
    Square(int length, int width, const string& colour, int position_x, int position_y);
    Square(const Square& copy);

public:
    Shape* clone() override;
    ~Square() override;
    vector<vector<CanvasCell>> draw() override;
};

#endif
