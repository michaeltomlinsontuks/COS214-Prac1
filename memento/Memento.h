#ifndef MEMENTO_H
#define MEMENTO_H

#include "../shapes/Shape.h"
#include "../TestingFramework/array.h"

class Canvas;

class Memento
{
	friend string to_string(const Memento &);
	friend void wilmarTesting();
	friend Canvas;
	template <typename T> friend class Array;

private:
	Array<Shape> *shapes;
	Memento(vector<Shape *> &elements);
	Memento(Memento &copy);
	// add to diagramf
	~Memento();
	bool operator==(const Memento &);
};
string to_string(const Memento &);

#endif
