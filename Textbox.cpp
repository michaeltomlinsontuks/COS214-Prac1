#include "Textbox.h"

Shape* Textbox::clone() {
    Logger::getInstance()->info("Textbox cloned with values: length = " + std::to_string(this->getLength()) + ", width = " + std::to_string(this->getWidth()) + ", colour = " + this->getColour() + ", position_x = " + std::to_string(this->getPositionX()) + ", position_y = " + std::to_string(this->getPositionY()) + ", text = " + this->text);
    return new Textbox(*this);
}

Textbox::Textbox(int length, int width, const string& colour, int position_x, int position_y, const string& text)
    : Shape(length, width, colour, position_x, position_y), text(text) {
    Logger::getInstance()->info("Textbox created with values: length = " + std::to_string(this->getLength()) + ", width = " + std::to_string(this->getWidth()) + ", colour = " + this->getColour() + ", position_x = " + std::to_string(this->getPositionX()) + ", position_y = " + std::to_string(this->getPositionY()) + ", text = " + this->text);
}

Textbox::Textbox(const Textbox& copy)
    : Shape(copy), text(copy.text) {
    Logger::getInstance()->info("Textbox copied with values: length = " + std::to_string(copy.getLength()) + ", width = " + std::to_string(copy.getWidth()) + ", colour = " + copy.getColour() + ", position_x = " + std::to_string(copy.getPositionX()) + ", position_y = " + std::to_string(copy.getPositionY()) + ", text = " + copy.text);
}

Textbox::~Textbox() {
    // Default destructor
}

vector<vector<CanvasCell>> Textbox::draw() {
    Logger::getInstance()->info("Textbox drawn with values: length = " + std::to_string(this->getLength()) + ", width = " + std::to_string(this->getWidth()) + ", colour = " + this->getColour() + ", position_x = " + std::to_string(this->getPositionX()) + ", position_y = " + std::to_string(this->getPositionY()) + ", text = " + this->text);
    vector<vector<CanvasCell>> result(getLength(), vector<CanvasCell>(getWidth(), CanvasCell(getColour(), ' ')));
    if (text.empty() || getWidth() == 0 || getLength() == 0) return result;

    // Center the text in the box
    int textLen = static_cast<int>(text.size());
    int row = getLength() / 2; // vertical center
    int colStart = (getWidth() - textLen) / 2;
    if (colStart < 0) colStart = 0;
    //Use switch-case to convert color code to use Intense Black text on existing background color
    //Apparently switch-cases can't do strings
    std::string code;
    if (getColour() == REDHB) code = BHBLK_ON_REDHB;
    else if (getColour() == GRNHB) code = BHBLK_ON_GRNHB;
    else if (getColour() == BLUHB) code = BHBLK_ON_BLUHB;
    else if (getColour() == YELHB) code = BHBLK_ON_YELHB;
    else if (getColour() == MAGHB) code = BHBLK_ON_MAGHB;
    else if (getColour() == CYNHB) code = BHBLK_ON_CYNHB;
    else if (getColour() == WHTHB) code = BHBLK_ON_WHTHB;
    else code = BHBLK_ON_WHTHB; // Fallback to white if unknown
    for (int i = 0; i < textLen && (colStart + i) < getWidth(); ++i) {
        result[row][colStart + i] = CanvasCell(code, text[i]);
    }
    return result;
}
