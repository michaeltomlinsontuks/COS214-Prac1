#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape.h"
#include "array.h"

class Canvas;

class Memento
{
	friend string to_string(const Memento &);
	friend void wilmarTesting();
	friend Canvas;

private:
	Array<Shape> *shapes;
	Memento(vector<Shape *> &elements);

public:
	Memento(Memento &copy);
	// add to diagramf
	~Memento();
	bool operator==(const Memento &);
};
string to_string(const Memento &);

#endif
