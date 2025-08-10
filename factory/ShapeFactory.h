#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "../shape/Shape.h"

class ShapeFactory {
public:
    virtual Shape* createShape(int length, int width, const std::string& colour, int position_x, int position_y) = 0;
    virtual std::string toString() = 0;
    virtual ~ShapeFactory() {}
};

#endif
