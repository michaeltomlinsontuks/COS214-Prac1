#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

// =============================
// Factory Method, Prototype
// Square is a concrete product class representing squares. Inherits from Shape and implements clone().
// =============================

class Square : public Shape {
public:
    Shape* clone(); // Prototype pattern method
};

#endif // SQUARE_H
