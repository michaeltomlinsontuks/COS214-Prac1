#ifndef CANVAS_H
#define CANVAS_H

class Canvas {

private:
	vector<Shape*> shapes;

public:
	Memento* captureCurrent();

	void undoAction(Memento* prev);

	Canvas();

	void ~Canvas();

	Shape* addShape();

	void removeShape(int shapeId);

	void duplicateShape(int shapeId);

	vector<Shape*> getShapeList();

	Shape* getShapeInfo(int shapeId);

	void clear();

	void draw();
};

#endif
