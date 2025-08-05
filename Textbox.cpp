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

vector<vector<CanvasCell>> Textbox::draw() {
    Logger::getInstance()->info("Textbox drawn with values: length = " + std::to_string(this->length) + ", width = " + std::to_string(this->width) + ", colour = " + this->colour + ", position_x = " + std::to_string(this->position_x) + ", position_y = " + std::to_string(this->position_y) + ", text = " + this->text);
    vector<vector<CanvasCell>> result(length, vector<CanvasCell>(width, CanvasCell(colour, ' ')));
    if (text.empty() || width == 0 || length == 0) return result;

    // Center the text in the box
    int textLen = static_cast<int>(text.size());
    int row = length / 2; // vertical center
    int colStart = (width - textLen) / 2;
    if (colStart < 0) colStart = 0;
    //Use switch-case to convert color code to use Intense Black text on existing background color
    //Apparently switch-cases can't do strings
    std::string code;
    if (colour == REDHB) code = BHBLK_ON_REDHB;
    else if (colour == GRNHB) code = BHBLK_ON_GRNHB;
    else if (colour == BLUHB) code = BHBLK_ON_BLUHB;
    else if (colour == YELHB) code = BHBLK_ON_YELHB;
    else if (colour == MAGHB) code = BHBLK_ON_MAGHB;
    else if (colour == CYNHB) code = BHBLK_ON_CYNHB;
    else if (colour == WHTHB) code = BHBLK_ON_WHTHB;
    else code = BHBLK_ON_WHTHB; // Fallback to white if unknown
    for (int i = 0; i < textLen && (colStart + i) < width; ++i) {
        result[row][colStart + i] = CanvasCell(code, text[i]);
    }
    return result;
}
