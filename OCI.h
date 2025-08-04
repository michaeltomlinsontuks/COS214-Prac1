#ifndef OCI_H
#define OCI_H

class OCI {

private:
	Logger* logger;
	bool running;

public:
	OCI();

	void ~OCI();

	void run();

	void displayBanner();

	void displayMenu(int menuCode);

private:
	void shapeSubMenu();

	void addShape();

	void removeShape();

	void duplicateShape();

	void getShapeList();

	void getShapeInfo();

	void canvasSubMenu();

	void clearCanvas();

	void drawCanvas();

	void undo();

	void redo();

	void exportSubMenu();

	void exportPNG();

	void exportPDF();

	void utilitiesSubMenu();

	void help();

	void log();

	void quit();

	int validateNumberInput(int max);
};

#endif
