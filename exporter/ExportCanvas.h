#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H

#include "../canvas/Canvas.h"

class ExportCanvas
{

public:
	ExportCanvas(Canvas *canvas);
	virtual ~ExportCanvas();
	void exportToFile();

protected:
	Canvas *canvas;
	virtual void prepareCanvas() = 0;

	virtual void renderElements() = 0;

	virtual void saveToFile() = 0;
};

#endif
