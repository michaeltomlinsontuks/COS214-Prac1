#ifndef MEMENTO_H
#define MEMENTO_H

class Memento {

private:
	Shape* shapes;

public:
	Memento(Shape* elements);

private:
	Memento(Memento& copy);
};

#endif
