//
// Created by Michael Tomlinson on 2025/08/03.
//
#include <iostream>
#include <string>
#include "loggerOCI/ANSI-color-codes.h"
#include "loggerOCI/OCI.h"
#include "TestingFramework/testing.h"
#include "memento/Caretaker.h"
#include "exporter/PDFExporter.h"
#include "exporter/PNGExporter.h"
void wilmarTesting();

int main()
{
    /*
    try
    {
        OCI oci;
        oci.run();
    }
    catch (const char *msg)
    {
        std::cerr << "Exception: " << msg << std::endl;
    }
    return 0;
    */
    wilmarTesting();
}

void wilmarTesting()
{
    vector<Shape *> *elements = new vector<Shape *>();
    RectangleFactory RF;
    RF.toString();
    for (int i = 1; i < 4; i++)
    {

        Shape *Rec = RF.createShape(i, i, REDHB, i, i);

        elements->push_back(Rec);
    }
    SquareFactory SF;
    SF.toString();
    for (int i = 1; i < 4; i++)
    {

        Shape *Sqr = SF.createShape(i + 4, i + 4, BLUHB, i + 4, i + 4);

        elements->push_back(Sqr);
    }

    TextboxFactory TF;
    TF.toString();
    for (int i = 1; i < 4; i++)
    {

        Shape *Text = TF.createShape(i + 6, i + 6, GRNHB, 40 + i + 6, 5, "Trees");

        elements->push_back(Text);
    }

    Memento* mem  = new Memento(*elements);
    Array<string> arrInstruction(0);

    string str = "TC";
    arrInstruction.insertNewItem(str);
    str = "==";
    arrInstruction.insertNewItem(str);

    Testing<Memento, Memento> testingMemento(*mem, *mem);
    testingMemento.createTestSuite(arrInstruction, "Memento test suite");
    Suite<Memento, Memento> *TS = testingMemento.getSuite(0);
    Caretaker careTakerTest;

    careTakerTest.addMemento(mem);

    Memento *copy = careTakerTest.getMemento();
    TS->textCompare(*copy, *mem);
    TS->equalsTest(*copy,*mem);

    for (int i = 0; i < int(elements->size()); i++)
    {
        delete elements->operator[](i);
    }

    Canvas *canvas = new Canvas();

    for (int i = 1; i < 4; i++)
    {
        int val = i * 3;

        canvas->addShape(i, val, val, REDHB, val, val, "Str");
    }
    PDFExporter pdf(canvas);
    PNGExporter png(canvas);

    pdf.exportToFile();
    png.exportToFile();

    careTakerTest.addMemento(canvas->captureCurrent());

    canvas->draw();
    canvas->removeShape(1);
    canvas->clear();
    canvas->draw();

    canvas->undoAction(careTakerTest.getMemento());
    canvas->draw();
    canvas->undoAction(copy);
    canvas->draw();
    delete canvas;
    delete elements;
}