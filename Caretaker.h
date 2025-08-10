#ifndef CARETAKER_H
#define CARETAKER_H
#include "Memento.h"
#include "Logger.h"
class Caretaker
{
private:
    Array<Memento> mementos;

public:
    Caretaker();
    ~Caretaker();
    void addMemento(Memento *memento);
    Memento *getMemento();
};

#endif


