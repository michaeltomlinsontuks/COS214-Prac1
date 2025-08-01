// =============================
// Factory Method
// SquareFactory is a concrete factory that creates Square objects. Implements createShape() and toString().
// =============================

#ifndef SQUAREFACTORY_H
#define SQUAREFACTORY_H

#include "ShapeFactory.h"
#include "Square.h"

class SquareFactory : public ShapeFactory {
public:
    Shape* createShape();
    void toString();
};

#endif // SQUAREFACTORY_H
