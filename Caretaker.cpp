#include "Caretaker.h"

Caretaker::Caretaker()
{

    mementos = Array<Memento>(3);
    Logger::getInstance()->info("Caretaker created");
    // can store 3 states in mementos
}
Caretaker::~Caretaker()
{
}
void Caretaker::addMemento(Memento *memento)
{
    mementos.push(memento);
    Logger::getInstance()->info("Memento added to caretaker");
}
Memento *Caretaker::getMemento()
{
    Logger::getInstance()->info("Memento retrieved from caretaker");
    return mementos.pop();
    // make sure of NULL checks.
}