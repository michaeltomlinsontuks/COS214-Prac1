#ifndef OCI_H
#define OCI_H

#include <iostream>
#include <string>
#include "Logger.h"
#include "ANSI-color-codes.h"
#include "Canvas.h"


class OCI {

private:
	Logger* logger;
	bool running;
	Canvas* canvas; // Add Canvas pointer

public:
	OCI();
	~OCI();

	void run();

	static void displayBanner();

	static void displayMenu(int menuCode);

private:
	void shapeSubMenu() const;

	void addShape() const;

	void removeShape() const;

	void duplicateShape() const;

	void getShapeList() const;

	void getShapeInfo() const;

	void canvasSubMenu() const;

	void clearCanvas() const;

	void drawCanvas() const;

	void undo() const;

	void redo() const;

	void exportSubMenu() const;

	void exportPNG() const;

	void exportPDF() const;

	void utilitiesSubMenu() const;

	static void help();

	void log() const;

	void quit();

	int validateNumberInput(const int max) const;
};

#endif
