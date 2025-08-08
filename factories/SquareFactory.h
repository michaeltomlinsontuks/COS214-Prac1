#ifndef SQUAREFACTORY_H
#define SQUAREFACTORY_H

#include "ShapeFactory.h"
#include "../shapes/Square.h"

class SquareFactory : ShapeFactory {


public:
    SquareFactory() = default;
	Shape* createShape(int length, int width, const std::string& colour, int position_x, int position_y);

	void toString();

	SquareFactory(SquareFactory& copy);
};

#endif
