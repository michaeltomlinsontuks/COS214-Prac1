#ifndef MEMENTO_H
#define MEMENTO_H

#include "../shape/Shape.h"
#include "../loggerOCI/array.h"
#include "../loggerOCI/Logger.h"

class Canvas;

class Memento
{
	friend Canvas;

private:
	Array<Shape> *shapes;
	Memento(vector<Shape *> &elements);

public:
	~Memento();
};

#endif
