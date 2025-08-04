#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H

class ExportCanvas {

private:
	Canvas* canvas;

public:
	void export();

private:
	void prepareCanvas();

	void renderElements();

	void saveToFile();
};

#endif
