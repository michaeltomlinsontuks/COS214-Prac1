#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"
class TextboxFactory; // Forward declaration

class Textbox : public Shape {

friend class TextboxFactory;
friend void prototypeTesting();

private:
    Textbox(int length, int width, const std::string& colour, int position_x, int position_y, const std::string& text);
    Textbox(const Textbox& copy);
    std::string text;

public:
    Shape* clone() override;
    ~Textbox() override;
    std::vector<std::vector<CanvasCell>> draw() override;
};

#endif
