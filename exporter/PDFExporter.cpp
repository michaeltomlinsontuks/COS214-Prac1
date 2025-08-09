#include "PDFExporter.h"

PDFExporter::PDFExporter(Canvas *canvas) : ExportCanvas(canvas) {}
PDFExporter::~PDFExporter() {}

void PDFExporter::prepareCanvas()
{
	if (canvas == NULL)
	{
		throw "Provide a canvas before exporting";
	}

	canvasOutput = new string("PDF EXPORT:\n");
	cout << "Canvas has been prepared for PDF export" << endl;
}
void PDFExporter::renderElements()
{
	if (canvas == NULL)
	{
		throw "Provide a canvas before exporting";
	}
	*canvasOutput += canvas->exportCanvas();
	cout << "Canvas has been locally rendered for PDF export" << endl;
}

void PDFExporter::saveToFile()
{

	cout << "What do you wish to save this PDF as? :[default is PDF.txt] ";
	string fileName = "";

	getline(std::cin, fileName);

	if (fileName.empty())
	{
		fileName = "PDF";
	}

	ofstream file(fileName + ".txt");
	if (!file)
	{
		cout << RED << "Error in producing a file" << CRESET << endl;
		return;
	}

	file << *canvasOutput;
	cout << "PDF successfully exported" << endl;
}
