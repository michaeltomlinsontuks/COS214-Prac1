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
    for (int i = 1; i < 4; i++)
    {

        Shape *Rec = RF.createShape(i, i, REDHB, i, i);

        elements->push_back(Rec);
    }
    SquareFactory SF;
    for (int i = 1; i < 4; i++)
    {

        Shape *Sqr = SF.createShape(i, i, REDHB, i, i);

        elements->push_back(Sqr);
    }

    TextboxFactory TF;
    for (int i = 1; i < 4; i++)
    {

        Shape *Text = SF.createShape(i, i, REDHB, i, i);

        elements->push_back(Text);
    }

    Memento mem(*elements);
    Array<string> arrInstruction(0);

    arrInstruction.insert("TC");
    arrInstruction.insert("==");

    Testing<Memento, Memento> testingMemento(mem, mem);
    testingMemento.createTestSuite(arrInstruction, "Memento test suite");
    Suite<Memento, Memento> *TS = testingMemento.getSuite(0);
    Caretaker careTakerTest;

    careTakerTest.addMemento(mem);

    Memento *copy = careTakerTest.getMemento();
    TS->textCompare(*copy, mem);
    TS->equalsTest(*copy, mem);

    for (int i = 0; i < int(elements->size()); i++)
    {
        delete elements->operator[](i);
    }
    delete copy;
    delete elements;

    Canvas *canvas = new Canvas();

    for (int i = 1; i < 4; i++)
    {
        int val = i;

        canvas->addShape(val, val, val, REDHB, val, val);
    }
    PDFExporter pdf(canvas);
    PNGExporter png(canvas);

    pdf.exportToFile();
    png.exportToFile();

    delete canvas;
}