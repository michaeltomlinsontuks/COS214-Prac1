#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

// =============================
// Factory Method
// RectangleFactory is a concrete factory that creates Rectangle objects. Implements createShape() and toString().
// =============================

#include "ShapeFactory.h"
#include "Rectangle.h"

class RectangleFactory : public ShapeFactory {
public:
    Shape* createShape() override;
    std::string toString() override;
};

#endif // RECTANGLEFACTORY_H
