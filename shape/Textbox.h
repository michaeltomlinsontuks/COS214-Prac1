#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <vector>
#include <string>
#include "Shape.h"
#include "../canvas/CanvasCell.h"
using std::vector;
using std::string;

class TextboxFactory; // Forward declaration

class Textbox : public Shape {

friend class TextboxFactory;
friend void prototypeTesting();

private:
    Textbox(int length, int width, const string& colour, int position_x, int position_y, const string& text);
    Textbox(const Textbox& copy);
    std::string text;

public:
    Shape* clone() override;
    ~Textbox() override;
    vector<vector<CanvasCell>> draw() override;
};

#endif
