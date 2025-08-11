#include "PNGExporter.h"

PNGExporter::PNGExporter(Canvas *canvas) : ExportCanvas(canvas) {}
PNGExporter::~PNGExporter() {}

void PNGExporter::prepareCanvas()
{
	if (getCanvas() == NULL)
	{
		throw "Provide a canvas before exporting";
	}

	canvasOutput = new string("PNG EXPORT:\n");
	Logger::getInstance()->info("Canvas has been prepared for PNG export");
}
void PNGExporter::renderElements()
{
	if (getCanvas() == NULL)
	{
		throw "Provide a canvas before exporting";
	}
	*canvasOutput += getCanvas()->exportCanvas();
	Logger::getInstance()->info("Canvas has been rendered for PNG export");
}

void PNGExporter::saveToFile()
{
	ofstream file("PNG.txt");
	if (!file)
	{
		Logger::getInstance()->error("Error in producing a file");
		return;
	}

	file << *canvasOutput;
	Logger::getInstance()->info("Canvas has been saved to PNG.txt");
}
