// =============================
// Factory Method, Prototype
// Shape is the abstract base class for all shapes. It defines common attributes and declares the clone() method for the Prototype pattern.
// =============================

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
private:
    int length;
    int width;
    std::string colour;
    int positionX;
    int positionY;
public:
    virtual Shape* clone() const = 0; // Prototype pattern method
};

#endif // SHAPE_H
