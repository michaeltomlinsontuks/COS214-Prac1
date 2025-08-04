// =============================
// Factory Method
// TextboxFactory is a concrete factory that creates Textbox objects. Implements createShape() and toString().
// =============================

#ifndef TEXTBOXFACTORY_H
#define TEXTBOXFACTORY_H

#include "ShapeFactory.h"
#include "../shapes/Textbox.h"

class TextboxFactory : public ShapeFactory {
public:
    Shape* createShape();
    void toString();
};

#endif // TEXTBOXFACTORY_H
