#include "Textbox.h"

Shape* Textbox::clone() {
    Logger::getInstance()->info("Textbox cloned with values: length = " + std::to_string(this->length) + ", width = " + std::to_string(this->width) + ", colour = " + this->colour + ", position_x = " + std::to_string(this->position_x) + ", position_y = " + std::to_string(this->position_y) + ", text = " + this->text);
    return new Textbox(*this);
}

Textbox::Textbox(int length, int width, const string& colour, int position_x, int position_y, const string& text)
    : Shape(length, width, colour, position_x, position_y), text(text) {
    Logger::getInstance()->info("Textbox created with values: length = " + std::to_string(length) + ", width = " + std::to_string(width) + ", colour = " + colour + ", position_x = " + std::to_string(position_x) + ", position_y = " + std::to_string(position_y) + ", text = " + text);
}

Textbox::Textbox(const Textbox& copy)
    : Shape(copy), text(copy.text) {
    Logger::getInstance()->info("Textbox copied with values: length = " + std::to_string(copy.length) + ", width = " + std::to_string(copy.width) + ", colour = " + copy.colour + ", position_x = " + std::to_string(copy.position_x) + ", position_y = " + std::to_string(copy.position_y) + ", text = " + copy.text);
}

Textbox::~Textbox() {
    // Default destructor
}

vector<vector<char>> Textbox::draw() {
    throw "Textbox::draw - Not yet implemented";
}
