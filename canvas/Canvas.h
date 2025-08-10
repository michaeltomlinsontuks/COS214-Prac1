#ifndef CANVAS_H
#define CANVAS_H

#include "../shape/Shape.h"
#include "../factory/RectangleFactory.h"
#include "../factory/SquareFactory.h"
#include "../factory/TextboxFactory.h"
#include "../loggerOCI/ANSI-color-codes.h"
#include "../loggerOCI/Logger.h"
#include "../memento/Memento.h"
#include "CanvasCell.h"

class Canvas {
friend void canvasTesting();
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
	std::string exportCanvas();

	void generateCanvas();
};

#endif
