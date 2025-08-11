#include "ExportCanvas.h"

ExportCanvas::ExportCanvas(Canvas *canvas)
{
	this->canvas = canvas;
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

void ExportCanvas::prepareCanvas()
{
	if (getCanvas() == NULL)
	{
		throw "Provide a canvas before exporting";
	}

	canvasOutput = new string("EXPORT:\n");
	Logger::getInstance()->info("Canvas has been prepared for PNG export");
}
void ExportCanvas::renderElements()
{
	if (getCanvas() == NULL)
	{
		throw "Provide a canvas before exporting";
	}
	*canvasOutput += getCanvas()->exportCanvas();
	Logger::getInstance()->info("Canvas has been rendered");
}
