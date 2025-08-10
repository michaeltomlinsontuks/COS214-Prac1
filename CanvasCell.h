#ifndef CANVAS_CELL_H
#define CANVAS_CELL_H

#include <string>
#include "ANSI-color-codes.h"

struct CanvasCell {
    std::string colorCode; // e.g., BLKB, REDB, etc.
    char ch;              // character to display
    CanvasCell(const std::string& color = BLKB, char c = ' ') : colorCode(color), ch(c) {}
};

#endif
