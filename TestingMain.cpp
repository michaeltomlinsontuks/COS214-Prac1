//
// Created by Michael Tomlinson on 2025/08/03.
//

#include <iostream>
#include <string>
#include "ANSI-color-codes.h"
//Prototype
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Textbox.h"
//Factory Method
#include "RectangleFactory.h"
#include "SquareFactory.h"
#include "TextboxFactory.h"
//Template Method
#include "Canvas.h"
#include "ExportCanvas.h"
#include "PDFExporter.h"
#include "PNGExporter.h"
//Memento
#include "Memento.h"
#include "Caretaker.h"
//Other
#include "Logger.h"
#include "array.h"
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
    endTest("Create Canvas", Logger::getInstance()->getLastLine()=="[INFO] Canvas constructed");
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
    startTest("Create Canvas");
    Canvas *canvas = new Canvas();
    endTest("Create Canvas", Logger::getInstance()->getLastLine()=="[INFO] Canvas constructed");
    startTest("Capture Current");
    Memento *memento = canvas->captureCurrent();
    endTest("Capture Current", Logger::getInstance()->getLastLine()=="[INFO] Memento created");
    startTest("Undo Action");
    canvas->undoAction(memento);
    endTest("Undo Action", Logger::getInstance()->getLastLine()=="[INFO] Canvas has been restored to previous state");
    delete canvas;
}

void coverageCompleter()
{
    prototypeTesting();
    factoryMethodTesting();
    templateMethodTesting();
    mementoTesting();
}

int main()
{
    coverageCompleter();
    return 0;
}