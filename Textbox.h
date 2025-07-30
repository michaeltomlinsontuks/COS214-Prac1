#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"
#include <string>

// =============================
// Factory Method, Prototype
// Textbox is a concrete product class representing textboxes. Inherits from Shape, adds a text attribute, and implements clone().
// =============================

class Textbox : public Shape {
public:
    std::string text;
    Textbox();
    // Textbox-specific methods
};

#endif // TEXTBOX_H
