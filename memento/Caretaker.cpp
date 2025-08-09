#include "Caretaker.h"

Caretaker::Caretaker()
{

    mementos = Array<Memento>(3);
    // can store 3 states in mementos
}
Caretaker::~Caretaker()
{
}
void Caretaker::addMemento(Memento &memento)
{
    mementos.insertNewItem(memento);
    // makes a copy of the memento
}
Memento *Caretaker::getMemento()
{
    return mementos.pop();
    // make sure of NULL checks.
}