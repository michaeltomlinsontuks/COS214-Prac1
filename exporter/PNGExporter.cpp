#include "PNGExporter.h"

PNGExporter::PNGExporter(Canvas *canvas) : ExportCanvas(canvas) {}
PNGExporter::~PNGExporter() {}



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
