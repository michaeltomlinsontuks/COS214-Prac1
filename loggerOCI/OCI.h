#ifndef OCI_H
#define OCI_H

#include "Logger.h"
#include "../canvas/Canvas.h"
#include "../memento/Caretaker.h"
#include "../memento/Memento.h"
#include "../exporter/PDFExporter.h"
#include "../exporter/PNGExporter.h"

// Forward declaration for main
int main();


class OCI {

private:
	Logger* logger;
	bool running;
	Canvas* canvas; // Add Canvas pointer
	Caretaker* caretaker;
	Memento* current;

	friend int ::main(); // Allow main() in DemoMain.cpp to access private/protected members

public:
	OCI();
	~OCI();

	void run();

	static void displayBanner();

	static void displayMenu(int menuCode);

private:
	void shapeSubMenu();

	void addShape();

	void removeShape();

	void duplicateShape();

	void getShapeList() const;

	void getShapeInfo() const;

	void canvasSubMenu();

	void clearCanvas() const;

	void drawCanvas() const;

	void undo();

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
