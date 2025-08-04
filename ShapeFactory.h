#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

class ShapeFactory {


protected:
	Shape* createShape();

	void toString();

public:
	ShapeFactory(ShapeFactory& copy);
};

#endif
