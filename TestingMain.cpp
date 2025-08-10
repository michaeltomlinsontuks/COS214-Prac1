//
// Created by Michael Tomlinson on 2025/08/03.
//

#include <iostream>
#include <string>
#include "loggerOCI/ANSI-color-codes.h"
#include "canvas/Canvas.h"
#include "loggerOCI/Logger.h"
#include "shape/Shape.h"
#include "shape/Rectangle.h"
#include "shape/Square.h"
#include "shape/Textbox.h"
#include "factory/RectangleFactory.h"
#include "factory/SquareFactory.h"
#include "factory/TextboxFactory.h"
#include "exporter/PDFExporter.h"
#include "exporter/PNGExporter.h"
#include "memento/Memento.h"
#include "memento/Caretaker.h"

using namespace std;
int suiteCount = 0;
int testCount = 0;
int passCount = 0;
int failCount = 0;
int totalTests = 0;
int totalPasses = 0;
int totalFails = 0;
//Game Plan Test Suite Printout
void startSuite(string suiteName)
{
    //Prints in Bold Blue Starting Suite SuiteNo: suiteName endl
    totalTests+=testCount;
    totalPasses+=passCount;
    totalFails+=failCount;
    testCount=0;
    passCount=0;
    failCount=0;
    cout << endl << "==============================================" << endl;
    cout << BHCYN << "\nStarting Suite " << ++suiteCount << ": " << suiteName << CRESET << endl;
}

void startTest(string testName)
{
    cout << BHMAG << "\nStarting Test " << ++testCount << ": " << testName << CRESET << endl;
}

void endSuite(string suiteName)
{
    //Prints Out Pass Fail numbers
    cout << BHCYN << "Suite " << suiteName << " Passed: " << passCount << " Failed: " << failCount << endl;
    cout << "==============================================" << endl;
    //Reset Counters
    totalTests+=testCount;
    totalPasses+=passCount;
    totalFails+=failCount;
    testCount=0;
    passCount=0;
    failCount=0;
}

void endTest(string testName, bool passed)
{
    if (passed)
    {
        cout << BHGRN << "Test: "<< testName << " Passed" << CRESET << endl;
        passCount++;
    }
    else
    {
        cout << BHRED << "Test: "<< testName << " Failed" << CRESET << endl;
        failCount++;
    }
}

//Friend function of anything it needs
void prototypeTesting()
{
    startSuite("Prototype Testing");
    //Create Shapes - Will need to be a friend to use the private constructor
    startTest("Create Rectangle");
    Shape *rectangle = new Rectangle(5,5,"Red",5,5);
    endTest("Create Rectangle",
        (Logger::getInstance()->getLastLine())==
        "[INFO] Rectangle created with values: length = 5, width = 5, colour = Red, position_x = 5, position_y = 5"
    );
    startTest("Create Square");
    Shape *square = new Square(5,5,"Blue",5,5);
    endTest("Create Square",
        (Logger::getInstance()->getLastLine())==
        "[INFO] Square created with values: length = 5, width = 5, colour = Blue, position_x = 5, position_y = 5"
    );
    startTest("Create Textbox");
    Shape *textbox = new Textbox(5,5,"Green",5,5,"Hello World");
    endTest("Create Textbox",
        (Logger::getInstance()->getLastLine())==
        "[INFO] Textbox created with values: length = 5, width = 5, colour = Green, position_x = 5, position_y = 5, text = Hello World"
    );
    startTest("Clone Rectangle");
    Shape *rectangleClone = rectangle->clone();
    endTest("Clone Rectangle", Logger::getInstance()->getLastLine()=="[INFO] Rectangle copied with values: length = 5, width = 5, colour = Red, position_x = 5, position_y = 5");
    startTest("Clone Square");
    Shape *squareClone = square->clone();
    endTest("Clone Square", Logger::getInstance()->getLastLine()=="[INFO] Square copied with values: length = 5, width = 5, colour = Blue, position_x = 5, position_y = 5");
    startTest("Clone Textbox");
    Shape *textboxClone = textbox->clone();
    endTest("Clone Textbox", Logger::getInstance()->getLastLine()=="[INFO] Textbox copied with values: length = 5, width = 5, colour = Green, position_x = 5, position_y = 5, text = Hello World");
    delete rectangle;
    delete square;
    delete textbox;
    delete rectangleClone;
    delete squareClone;
    delete textboxClone;
    endSuite("Prototype Testing");
}

void factoryMethodTesting()
{
    startSuite("Factory Method Testing");
    startTest("Create RectangleFactory");
    RectangleFactory* rectangleFactory = new RectangleFactory();
    Shape* rectangle = rectangleFactory->createShape(5, 5, "Red", 5, 5);
    endTest("Create RectangleFactory", Logger::getInstance()->getLastLine()==
        "[INFO] Rectangle created with values: length = 5, width = 5, colour = Red, position_x = 5, position_y = 5");
    startTest("Create SquareFactory");
    SquareFactory* squareFactory = new SquareFactory();
    Shape* square = squareFactory->createShape(5, 5, "Blue", 5, 5);
    endTest("Create SquareFactory", Logger::getInstance()->getLastLine()==
        "[INFO] Square created with values: length = 5, width = 5, colour = Blue, position_x = 5, position_y = 5");
    startTest("Create TextboxFactory");
    TextboxFactory* textboxFactory = new TextboxFactory();
    Shape* textbox = textboxFactory->createShape(5, 5, "Green", 5, 5, "Hello World");
    endTest("Create TextboxFactory", Logger::getInstance()->getLastLine()==
        "[INFO] Textbox created with values: length = 5, width = 5, colour = Green, position_x = 5, position_y = 5, text = Hello World"
        );
    delete rectangle;
    delete square;
    delete textbox;
    //ToStrings - Pure Mock functionality never understood what they wanted
    startTest("RectangleFactory toString");
    endTest("RectangleFactory toString", rectangleFactory->toString()=="RectangleFactory");
    startTest("SquareFactory toString");
    endTest("SquareFactory toString", squareFactory->toString()=="SquareFactory");
    startTest("TextboxFactory toString");
    endTest("TextboxFactory toString", textboxFactory->toString()=="TextboxFactory");

    delete rectangleFactory;
    delete squareFactory;
    delete textboxFactory;
    endSuite("Factory Method Testing");
}

void templateMethodTesting()
{
    startSuite("Template Method Testing");
    startTest("Create Canvas");
    Canvas *canvas = new Canvas();
    endTest("Create Canvas", Logger::getInstance()->getLastLine()=="[INFO] Canvas::generateCanvas called");
    startTest("Export PDF");
    PDFExporter* pdfExporter = new PDFExporter(canvas);
    pdfExporter->exportToFile();
    endTest("Export PDF", Logger::getInstance()->getLastLine()=="[INFO] Canvas has been saved to PDF.txt");
    startTest("Export PNG");
    PNGExporter* pngExporter = new PNGExporter(canvas);
    pngExporter->exportToFile();
    endTest("Export PNG", Logger::getInstance()->getLastLine()=="[INFO] Canvas has been saved to PNG.txt");
    delete canvas;
    delete pdfExporter;
    delete pngExporter;
    endSuite("Template Method Testing");
}

void mementoTesting()
{
    startSuite("Memento Testing");
    startTest("Create Memento");
    Canvas *canvas = new Canvas();
    Memento *memento = canvas->captureCurrent();
    endTest("Create Memento", Logger::getInstance()->getLastLine()=="[INFO] Memento created");
    startTest("Create Caretaker");
    Caretaker *caretaker = new Caretaker();
    endTest("Create Caretaker", Logger::getInstance()->getLastLine()=="[INFO] Caretaker created");
    startTest("Add Memento");
    caretaker->addMemento(memento);
    endTest("Add Memento", Logger::getInstance()->getLastLine()=="[INFO] Memento added to caretaker");
    startTest("Get Memento");
    Memento *memento2 = caretaker->getMemento();
    endTest("Get Memento", Logger::getInstance()->getLastLine()=="[INFO] Memento retrieved from caretaker");
    delete canvas;
    delete memento;
    delete caretaker;
    endSuite("Memento Testing");
}

void canvasTesting()
{
    startSuite("Canvas Testing");

    // Test Canvas construction
    startTest("Create Canvas");
    Canvas *canvas = new Canvas();
    endTest("Create Canvas", Logger::getInstance()->getLastLine()=="[INFO] Canvas::generateCanvas called");

    // Test adding different shape types
    startTest("Add Rectangle to Canvas");
    Shape* rectangle = canvas->addShape(1, 10, 5, "Red", 10, 5);
    endTest("Add Rectangle to Canvas",
        Logger::getInstance()->getLastLine().find("Canvas::addShape called with shapeType = 1") != string::npos &&
        rectangle != nullptr);

    startTest("Add Square to Canvas");
    Shape* square = canvas->addShape(2, 8, 8, "Blue", 25, 8);
    endTest("Add Square to Canvas",
        Logger::getInstance()->getLastLine().find("Canvas::addShape called with shapeType = 2") != string::npos &&
        square != nullptr);

    startTest("Add Textbox to Canvas");
    Shape* textbox = canvas->addShape(3, 15, 3, "Green", 40, 12, "Test Text");
    endTest("Add Textbox to Canvas",
        Logger::getInstance()->getLastLine().find("Canvas::addShape called with shapeType = 3") != string::npos &&
        textbox != nullptr);

    // Test invalid shape type
    startTest("Add Invalid Shape Type");
    Shape* invalidShape = canvas->addShape(99, 5, 5, "Yellow", 5, 5);
    endTest("Add Invalid Shape Type", invalidShape == nullptr);

    // Test getting shape list
    startTest("Get Shape List");
    vector<Shape*> shapeList = canvas->getShapeList();
    endTest("Get Shape List",
        Logger::getInstance()->getLastLine()=="[INFO] Canvas::getShapeList called" &&
        shapeList.size() == 3);

    // Test getting shape info
    startTest("Get Shape Info");
    Shape* shapeInfo = canvas->getShapeInfo(0);
    endTest("Get Shape Info",
        Logger::getInstance()->getLastLine()=="[INFO] Canvas::getShapeInfo called with shapeId = 0" &&
        shapeInfo != nullptr);

    // Test duplicate shape
    startTest("Duplicate Shape");
    canvas->duplicateShape(0);
    vector<Shape*> shapesAfterDupe = canvas->getShapeList();
    endTest("Duplicate Shape",
        Logger::getInstance()->getLastLine()=="[INFO] Canvas::getShapeList called" &&
        shapesAfterDupe.size() == 4);

    // Test canvas drawing
    startTest("Draw Canvas");
    canvas->draw();
    endTest("Draw Canvas", Logger::getInstance()->getLastLine()=="[INFO] Canvas::draw called");

    // Test canvas export
    startTest("Export Canvas");
    string exportedCanvas = canvas->exportCanvas();
    endTest("Export Canvas",
        Logger::getInstance()->getLastLine()=="[INFO] Canvas::draw called" &&
        !exportedCanvas.empty());

    // Test memento creation and undo
    startTest("Capture Current State");
    Memento* memento = canvas->captureCurrent();
    endTest("Capture Current State",
        Logger::getInstance()->getLastLine()=="[INFO] Canvas::captureCurrent called" &&
        memento != nullptr);

    // Add another shape before undo
    startTest("Add Shape Before Undo");
    canvas->addShape(1, 3, 3, "Purple", 60, 15);
    vector<Shape*> shapesBeforeUndo = canvas->getShapeList();
    endTest("Add Shape Before Undo", shapesBeforeUndo.size() == 5);

    // Test undo action
    startTest("Undo Action");
    canvas->undoAction(memento);
    vector<Shape*> shapesAfterUndo = canvas->getShapeList();
    endTest("Undo Action",
        Logger::getInstance()->getLastLine()=="[INFO] Canvas::generateCanvas called" &&
        shapesAfterUndo.size() == 4);

    // Test undo with null memento
    startTest("Undo with Null Memento");
    canvas->undoAction(nullptr);
    endTest("Undo with Null Memento", Logger::getInstance()->getLastLine()=="[INFO] Canvas::undoAction called");

    // Test remove shape
    startTest("Remove Shape");
    canvas->removeShape(0);
    vector<Shape*> shapesAfterRemove = canvas->getShapeList();
    endTest("Remove Shape",
        Logger::getInstance()->getLastLine()=="[INFO] Canvas::getShapeList called" &&
        shapesAfterRemove.size() == 3);

    // Test clear canvas
    startTest("Clear Canvas");
    canvas->clear();
    vector<Shape*> shapesAfterClear = canvas->getShapeList();
    endTest("Clear Canvas",
        Logger::getInstance()->getLastLine()=="[INFO] Canvas::getShapeList called" &&
        shapesAfterClear.size() == 0);

    // Test generate canvas after clear
    startTest("Generate Canvas After Clear");
    canvas->generateCanvas();
    endTest("Generate Canvas After Clear", Logger::getInstance()->getLastLine()=="[INFO] Canvas::generateCanvas called");

    delete canvas;
    endSuite("Canvas Testing");
}

void loggerTesting()
{
    startSuite("Logger Testing");
    startTest("Log Info");
    Logger::getInstance()->info("Hello World");
    endTest("Log Info", Logger::getInstance()->getLastLine()=="[INFO] Hello World");
    startTest("Log Error");
    Logger::getInstance()->error("Hello World");
    endTest("Log Error", Logger::getInstance()->getLastLine()=="[ERROR] Hello World");
    startTest("Log Warning");
    Logger::getInstance()->warning("Hello World");
    endTest("Log Warning", Logger::getInstance()->getLastLine()=="[WARNING] Hello World");
    startTest("Log To Console");
    Logger::getInstance()->log("Hello World", Logger::INFO, true);
    endTest("Log To Console", Logger::getInstance()->getLastLine()=="[INFO] Hello World");
    startTest("Print Log");
    Logger::getInstance()->printLogFile();
    endTest("Print Log", true);
    startTest("Clear Log");
    Logger::getInstance()->clearLogs();
    endTest("Clear Log", true);
    startTest("Logger Coverage");
    Logger::getInstance()->getLogLevelColor(Logger::UNKNOWN);
    Logger::getInstance()->getLogLevelString(Logger::UNKNOWN);

    endSuite("Logger Testing");
}

void coverageCompleter()
{
    prototypeTesting();
    factoryMethodTesting();
    templateMethodTesting();
    mementoTesting();
    canvasTesting();
    loggerTesting();
}

int main()
{
    coverageCompleter();
    return 0;
}