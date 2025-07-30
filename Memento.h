//
// Created by Michael Tomlinson on 2025/07/30.
//

#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape.h"
#include vector

class Memento {
public:
    Memento(Shape* elements) : elements(elements) {}
private:
    std::vector<Shape*> elements; // Pointer to the shape element being saved

#endif //MEMENTO_H
