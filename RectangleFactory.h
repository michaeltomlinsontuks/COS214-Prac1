#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

class RectangleFactory : ShapeFactory {


public:
	Shape* createShape();

	void toString();

	RectangleFactory(RectangleFactory& copy);
};

#endif
