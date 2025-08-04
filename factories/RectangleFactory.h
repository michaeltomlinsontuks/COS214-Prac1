#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

// =============================
// Factory Method
// RectangleFactory is a concrete factory that creates Rectangle objects. Implements createShape() and toString().
// =============================

#include "ShapeFactory.h"
#include "../shapes/Rectangle.h"

class RectangleFactory : public ShapeFactory {
public:
    Shape* createShape();
    void toString();
};

#endif // RECTANGLEFACTORY_H
