#ifndef MEMENTO_H
#define MEMENTO_H

#include "../shape/Shape.h"
#include "../testingFramework/array.h"

class Memento
{
	friend string to_string(const Memento& );

private:
	Array<Shape> *shapes;

public:
	Memento(vector<Shape *> &elements);
	Memento(Memento &copy);
	// add to diagram
	~Memento();
	bool operator==(const Memento&);
};
string to_string(const Memento&);

#endif
