#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

// =============================
// Factory Method
// ShapeFactory is the abstract base class for all shape factories. It declares the interface for creating shapes.
// =============================

#include "Shape.h"
#include <string>

class ShapeFactory {
public:
    virtual Shape* createShape() = 0;
    virtual std::string toString() = 0;
    virtual ~ShapeFactory() = default;
};

#endif // SHAPEFACTORY_H
