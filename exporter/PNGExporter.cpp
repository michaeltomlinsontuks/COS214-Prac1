#include "PNGExporter.h"

PNGExporter::PNGExporter(Canvas *canvas) : ExportCanvas(canvas) {}
PNGExporter::~PNGExporter() {}

void PNGExporter::prepareCanvas()
{
	if (canvas == NULL)
	{
		throw "Provide a canvas before exporting";
	}

	canvasOutput = new string("PNG EXPORT:\n");
	cout << "Canvas has been prepared for PNG export" << endl;
}
void PNGExporter::renderElements()
{
	if (canvas == NULL)
	{
		throw "Provide a canvas before exporting";
	}
	*canvasOutput += canvas->exportCanvas();
	cout << "Canvas has been locally rendered for PNG export" << endl;
}

void PNGExporter::saveToFile()
{

	cout << "What do you wish to save this PNG as? :[default is PNG.txt] ";
	string fileName = "";

	getline(std::cin, fileName);

	if (fileName.empty())
	{
		fileName = "PNG";
	}

	ofstream file(fileName + ".txt");
	if (!file)
	{
		cout << RED << "Error in producing a file" << CRESET << endl;
		return;
	}

	file << *canvasOutput;
	cout << "PNG successfully exported" << endl;
}
