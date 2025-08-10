#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

#include "ShapeFactory.h"
#include "Rectangle.h"

class RectangleFactory : ShapeFactory {


public:
    Shape* createShape(int length, int width, const std::string& colour, int position_x, int position_y);
	std::string toString();
};

#endif
