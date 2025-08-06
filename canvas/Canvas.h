#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "Shape.h"
#include "Memento.h"
#include "RectangleFactory.h"
#include "SquareFactory.h"
#include "TextboxFactory.h"
#include <string>
#include <iostream>
#include "ANSI-color-codes.h"
#include "CanvasCell.h"

class Canvas {

private:
	vector<Shape*> shapes;
	std::vector<std::vector<CanvasCell>> canvas;
	int width;
	int height;
	std::string canvasColour;

	void drawBorder();

public:
	Memento* captureCurrent();

	void undoAction(Memento* prev);

	Canvas();

	~Canvas();

	Shape* addShape(int shapeType, int length, int width, const std::string& colour, int x, int y, const std::string& text = "");

	void removeShape(int shapeId);

	void duplicateShape(int shapeId);

	vector<Shape*> getShapeList();

	Shape* getShapeInfo(int shapeId);

	void clear();

	void draw();

	void generateCanvas();
};

#endif
