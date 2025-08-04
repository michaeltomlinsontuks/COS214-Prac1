#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <vector>
#include <string>
#include "Shape.h"
using std::vector;
using std::string;

class TextboxFactory; // Forward declaration

class Textbox : public Shape {

friend class TextboxFactory;

private:
    Textbox(int length, int width, const string& colour, int position_x, int position_y, const string& text);
    Textbox(const Textbox& copy);

public:
    string text;
    Shape* clone() override;
    ~Textbox() override;
    vector<vector<char>> draw() override;
};

#endif
