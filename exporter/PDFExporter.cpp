#include "PDFExporter.h"

PDFExporter::PDFExporter(Canvas *canvas) : ExportCanvas(canvas) {}
PDFExporter::~PDFExporter() {}

void PDFExporter::prepareCanvas()
{
	if (getCanvas() == NULL)
	{
		cout<<" canvas is null"<<endl;
		throw "Provide a canvas before exporting";
	}

	canvasOutput = new string("PDF EXPORT:\n");
	Logger::getInstance()->info("Canvas has been prepared for PDF export");
}
void PDFExporter::renderElements()
{
	if (getCanvas() == NULL)
	{
		throw "Provide a canvas before exporting";
	}
	*canvasOutput += getCanvas()->exportCanvas();
	Logger::getInstance()->info("Canvas has been locally rendered for PDF export");
}

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
