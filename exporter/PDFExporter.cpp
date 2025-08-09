#include "PDFExporter.h"

PDFExporter::PDFExporter(Canvas *canvas) : ExportCanvas(canvas){}
PDFExporter::~PDFExporter(){}

void PDFExporter::prepareCanvas()
{
}
void PDFExporter::renderElements()
{
}

void PDFExporter::saveToFile()
{
	// TODO - implement PDFExporter::saveToFile
	throw "Not yet implemented: PDFExporter::saveToFile()";
}
