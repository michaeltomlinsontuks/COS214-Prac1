#ifndef MEMENTO_H
#define MEMENTO_H

#include "../shapes/Shape.h"

class Memento {

public:
	Shape* shapes;

public:
	Memento(Shape* elements);

private:
	Memento(Memento& copy);
};

#endif
