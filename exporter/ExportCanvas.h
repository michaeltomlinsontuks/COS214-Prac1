#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H

#include "../canvas/Canvas.h"
#include "../loggerOCI/Logger.h"
class ExportCanvas
{

public:
	ExportCanvas(Canvas *canvas);
	virtual ~ExportCanvas();
	void exportToFile();

protected:
	string *canvasOutput;
	Canvas *getCanvas() { return canvas; }

private:
	Canvas *canvas;

	virtual void prepareCanvas() ;

	virtual void renderElements() ;

	virtual void saveToFile() = 0;
};

#endif
