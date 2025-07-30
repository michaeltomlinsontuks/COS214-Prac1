#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

// =============================
// Factory Method
// ShapeFactory is the abstract base class for all shape factories. It declares the interface for creating shapes.
// =============================

#include "Shape.h"
#include <string>

class ShapeFactory {
protected:
    virtual Shape* createShape() = 0;
    virtual void toString() = 0;
};

#endif // SHAPEFACTORY_H
