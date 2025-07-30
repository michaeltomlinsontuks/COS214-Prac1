// =============================
// Factory Method
// TextboxFactory is a concrete factory that creates Textbox objects. Implements createShape() and toString().
// =============================

#ifndef TEXTBOXFACTORY_H
#define TEXTBOXFACTORY_H

#include "ShapeFactory.h"
#include "Textbox.h"

class TextboxFactory : public ShapeFactory {
public:
    Shape* createShape() override;
    std::string toString() override;
};

#endif // TEXTBOXFACTORY_H
