#ifndef PNGEXPORTER_H
#define PNGEXPORTER_H

#include "ExportCanvas.h"

class PNGExporter : public ExportCanvas
{
public:
	PNGExporter(Canvas *canvas);
	virtual ~PNGExporter();

private:


	virtual void saveToFile();
};

#endif
