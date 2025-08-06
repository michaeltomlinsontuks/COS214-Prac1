#ifndef TEXTBOXFACTORY_H
#define TEXTBOXFACTORY_H

#include "ShapeFactory.h"
#include "Textbox.h"

class TextboxFactory : ShapeFactory {


public:
    TextboxFactory() = default;
    Shape* createShape(int length, int width, const std::string& colour, int position_x, int position_y, const std::string& text);
    // Implement the base class pure virtual function to avoid abstract class error - really weird
    Shape* createShape(int length, int width, const std::string& colour, int position_x, int position_y) override {
        // Provide a default text if not specified
        return createShape(length, width, colour, position_x, position_y, "");
    }
    void toString() override;
    TextboxFactory(TextboxFactory& copy);
};

#endif
