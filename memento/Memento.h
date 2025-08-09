#ifndef MEMENTO_H
#define MEMENTO_H

#include "../shape/Shape.h"
#include "../testingFramework/array.h"

class Canvas;

class Memento
{
	friend string to_string(const Memento &);
	friend void wilmarTesting();
	friend Canvas;

private:
	Array<Shape> *shapes;
	Memento(vector<Shape *> &elements);

	// add to diagramf
public:
	Memento(Memento &copy);
	~Memento();
	bool operator==(const Memento &);
};
string to_string(const Memento &);

#endif
