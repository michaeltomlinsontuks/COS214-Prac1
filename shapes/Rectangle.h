#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

// =============================
// Factory Method, Prototype
// Rectangle is a concrete product class representing rectangles. Inherits from Shape and implements clone().
// =============================

class Rectangle : public Shape {
public:
    Shape* clone() const override; // Prototype pattern method
};

#endif // RECTANGLE_H
