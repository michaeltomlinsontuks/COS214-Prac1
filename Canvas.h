#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "Shape.h"

// =============================
// Factory Method, Prototype, Memento
// Canvas class holds all shape elements added to the canvas. It is responsible for managing the collection of shapes and supports Memento pattern methods for undo functionality.
// =============================

class Canvas {
private:
    std::vector<Shape*> shapes;
public:
    Memento* captureCurrent();
    void undoAction(Memento* prev);
};

#endif // CANVAS_H
