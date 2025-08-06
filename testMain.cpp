//
// Created by Michael Tomlinson on 2025/08/03.
//
#include <iostream>
#include <string>
#include "loggerOCI/ANSI-color-codes.h"
#include "loggerOCI/OCI.h"
#include "testingFramework/testing.h"

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
    for (int i = 1; i < 11; i++)
    {
        Shape *Rec = RF.createShape(i, i, REDHB, i, i);
        elements->push_back(Rec);
    }
    Memento mem(*elements);
    Testing<Memento, Memento> tsMemento(mem, mem);

    for (int i = 0; i < elements->size(); i++)
    {
        delete elements->operator[](i);
    }
    delete elements;
}