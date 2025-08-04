#include "Canvas.h"

Memento* Canvas::captureCurrent() {
	// TODO - implement Canvas::captureCurrent
	throw "Not yet implemented: Canvas::captureCurrent()";
}

void Canvas::undoAction(Memento* prev) {
    (void)prev;
    throw "Not yet implemented: Canvas::undoAction(Memento*)";
}

Canvas::Canvas() {
    // No shapes at construction; vector is default-initialized
}

Shape* Canvas::addShape(int shapeType, int length, int width, const std::string& colour, int x, int y, const std::string& text) {
    Shape* newShape = nullptr;
    switch (shapeType) {
        case 1: { // Rectangle
            RectangleFactory rectFactory;
            newShape = rectFactory.createShape(length, width, colour, x, y);
            break;
        }
        case 2: { // Square
            SquareFactory squareFactory;
            newShape = squareFactory.createShape(length, width, colour, x, y);
            break;
        }
        case 3: { // Textbox
            TextboxFactory textboxFactory;
            newShape = textboxFactory.createShape(length, width, colour, x, y, text);
            break;
        }
        default:
            return nullptr;
    }
    if (newShape) {
        shapes.push_back(newShape);
    }
    return newShape;
}

void Canvas::removeShape(int shapeId) {
    (void)shapeId;
    throw "Canvas::removeShape - Not yet implemented";
}

void Canvas::duplicateShape(int shapeId) {
    (void)shapeId;
    throw "Canvas::duplicateShape - Not yet implemented";
}

vector<Shape*> Canvas::getShapeList() {
    return shapes;
}

Shape* Canvas::getShapeInfo(int shapeId) {
    (void)shapeId;
    throw "Canvas::getShapeInfo - Not yet implemented";
}

void Canvas::clear() {
	throw "Canvas::clear - Not yet implemented";
}

void Canvas::draw() {
	throw "Canvas::draw - Not yet implemented";
}

Canvas::~Canvas() {
    // Clean up all shapes
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();
}
