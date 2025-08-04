#include "TextboxFactory.h"
#include "Textbox.h"

Shape* TextboxFactory::createShape(int length, int width, const std::string& colour, int position_x, int position_y, const std::string& text) {
    return new Textbox(length, width, colour, position_x, position_y, text);
}

void TextboxFactory::toString() {
    // Example implementation
    // std::cout << "TextboxFactory" << std::endl;
}

TextboxFactory::TextboxFactory(TextboxFactory& copy) {
    (void)copy;
    // Copy constructor implementation if needed
}
