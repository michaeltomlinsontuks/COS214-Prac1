#include "ExportCanvas.h"

ExportCanvas::ExportCanvas(Canvas *canvas) : canvas(canvas)
{
	canvasOutput = NULL;
}
ExportCanvas::~ExportCanvas()
{
	// doesnt hold canvas (has-a relationship)
	if (canvasOutput)
		delete canvasOutput;
}

void ExportCanvas::exportToFile()
{
	// repeated structure
	prepareCanvas();
	renderElements();
	saveToFile();
}
