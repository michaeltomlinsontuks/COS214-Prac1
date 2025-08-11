#include "PDFExporter.h"

PDFExporter::PDFExporter(Canvas *canvas) : ExportCanvas(canvas) {}
PDFExporter::~PDFExporter() {}



void PDFExporter::saveToFile()
{
	ofstream file("PDF.txt");
	if (!file)
	{
		Logger::getInstance()->error("Error in producing a file");
		return;
	}

	file << *canvasOutput;
	Logger::getInstance()->info("Canvas has been saved to PDF.txt");
}
