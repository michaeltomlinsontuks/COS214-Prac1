#include "TextboxFactory.h"

Shape* TextboxFactory::createShape(int length, int width, const std::string& colour, int position_x, int position_y, const std::string& text) {
    return new Textbox(length, width, colour, position_x, position_y, text);
}

std::string TextboxFactory::toString() {
    return "TextboxFactory";
}