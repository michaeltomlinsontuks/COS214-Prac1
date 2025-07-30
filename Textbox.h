#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"
#include <string>

// =============================
// Factory Method, Prototype
// Textbox is a concrete product class representing textboxes. Inherits from Shape, adds a text attribute, and implements clone().
// =============================

class Textbox : public Shape {
private:
    std::string text; // Text content of the textbox
public:
    Shape* clone(); // Prototype pattern method
};

#endif // TEXTBOX_H
