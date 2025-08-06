#ifndef MEMENTO_H
#define MEMENTO_H

#include "../shape/Shape.h"
#include "../testingFramework/array.h"
class Memento {

private:
	Array<Shape>* shapes;

public:
	Memento(vector<Shape*>& elements);
	Memento(Memento& copy);
	// add to diagram 
	~Memento();
	

};

#endif
