#ifndef PDFEXPORTER_H
#define PDFEXPORTER_H

#include "ExportCanvas.h"

class PDFExporter : public ExportCanvas {


private:
	void saveToFile();
};

#endif
