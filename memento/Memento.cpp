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

string to_string(const Memento &obj)
{
	string output = "";
	for (int i = 0; i < obj.shapes->getLength(); i++)
	{
		output += "Shape " + to_string(i) + ": \n";
		output += to_string(obj.shapes[i]) + "\n";
	}
	return output;
}

bool Memento::operator==(const Memento &copy)
{
	if (this->shapes->getLength() != copy.shapes->getLength())
		return false;

	for (int i = 0; i < shapes->getLength(); i++)
	{
		if (!(shapes->getIndex(i) == copy.shapes->getIndex(i)))
			return false;
	}

	return true;
}