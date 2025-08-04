#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

#include "ShapeFactory.h"
#include "Rectangle.h"

class RectangleFactory : ShapeFactory {


public:
    RectangleFactory() = default;
    Shape* createShape(int length, int width, const std::string& colour, int position_x, int position_y);

	void toString();

	RectangleFactory(RectangleFactory& copy);
};

#endif
