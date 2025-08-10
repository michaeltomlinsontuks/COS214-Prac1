#ifndef SQUAREFACTORY_H
#define SQUAREFACTORY_H

#include "ShapeFactory.h"
#include "../shape/Square.h"

class SquareFactory : ShapeFactory {


public:
	Shape* createShape(int length, int width, const std::string& colour, int position_x, int position_y);

	std::string toString();
};

#endif
