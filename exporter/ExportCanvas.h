#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H

#include "../canvas/Canvas.h"

class ExportCanvas {

private:
	Canvas* canvas;

public:
	void exportToFile();

private:
	void prepareCanvas();

	void renderElements();

	void saveToFile();
};

#endif
