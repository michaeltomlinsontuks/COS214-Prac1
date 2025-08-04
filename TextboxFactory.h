#ifndef TEXTBOXFACTORY_H
#define TEXTBOXFACTORY_H

class TextboxFactory : ShapeFactory {


public:
	Shape* createShape();

	void toString();

	TextboxFactory(TextboxFactory& copy);
};

#endif
