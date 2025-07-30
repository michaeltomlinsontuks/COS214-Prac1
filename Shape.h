// =============================
// Factory Method, Prototype
// Shape is the abstract base class for all shapes. It defines common attributes and declares the clone() method for the Prototype pattern.
// =============================

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    int length;
    int width;
    std::string colour;
    int positionX;
    int positionY;
    virtual ~Shape() = default;
    // Add virtual methods for drawing, cloning, etc.
};

#endif // SHAPE_H
