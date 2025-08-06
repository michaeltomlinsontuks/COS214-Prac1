#include "Memento.h"

Memento::Memento(vector<Shape *> &elements)
{

	shapes = new Array<Shape>(elements.size());

	for (int i = 0; i < shapes->getLength(); i++)
	{
		shapes[i].insertNewItem(*elements[i]->clone());
	}
}
Memento::Memento(Memento &copy)
{
	shapes = new Array<Shape>(copy.shapes->getLength());

	for (int i = 0; i < shapes->getLength(); i++)
	{
		shapes[i].insertNewItem(*copy.shapes->getIndex(i));
	}
}
Memento::~Memento()
{

	delete shapes;
}