#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"

class ShapeFactory {
public:
    virtual Shape* createShape(int length, int width, const std::string& colour, int position_x, int position_y) = 0;
    virtual void toString() = 0;
    virtual ~ShapeFactory() {}
};

#endif
