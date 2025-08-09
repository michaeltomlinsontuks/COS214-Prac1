#include "ExportCanvas.h"

ExportCanvas::ExportCanvas(Canvas *canvas) : canvas(canvas)
{
}
ExportCanvas::~ExportCanvas()
{
	// doesnt hold canvas (has-a relationship)
}

void ExportCanvas::exportToFile()
{
	// repeated structure
	prepareCanvas();
	renderElements();
	saveToFile();
}
