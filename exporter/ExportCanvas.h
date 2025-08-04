//
// Created by Michael Tomlinson on 2025/07/30.
//

#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H

#include "Canvas.h"

class ExportCanvas {
private:
    Canvas* canvas;
    void prepareCanvas();
    void renderElements();
    virtual void saveToFile();
public:
    void export();
}

#endif //EXPORTCANVAS_H
