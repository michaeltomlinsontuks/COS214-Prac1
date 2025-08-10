#ifndef MEMENTO_H
#define MEMENTO_H

#include "../shape/Shape.h"
#include "../loggerOCI/array.h"
#include "../loggerOCI/Logger.h"

class Canvas;

class Memento
{
	/*
	Removing the testing stuff for the fitchfork submission
	friend string to_string(const Memento &);
	friend void wilmarTesting();
	*/
	friend Canvas;

private:
	Array<Shape> *shapes;
	Memento(vector<Shape *> &elements);

public:
	//Memento(Memento &copy);
	// add to diagram
	~Memento();
	//bool operator==(const Memento &);
};

//Removing the testing stuff for the fitchfork submission
//string to_string(const Memento &);

#endif
