#ifndef PDFEXPORTER_H
#define PDFEXPORTER_H

#include "ExportCanvas.h"

class PDFExporter : public ExportCanvas
{
public:
	PDFExporter(Canvas * canvas);
	virtual ~PDFExporter();

protected:
	virtual void prepareCanvas();

	virtual void renderElements();

	virtual void saveToFile();
};

#endif
