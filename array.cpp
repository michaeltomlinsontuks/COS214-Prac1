
#include "array.h"
#include "Shape.h"
//Removing the testing stuff for the fitchfork submission
/*
string to_string(Array<Shape> &array)
{
    string obj = "[ ";
    for (int i = 0; i < array.getLength(); i++)
    {
        if (array[i])
        {
            obj += to_string(array[i]);
        }
        else
            obj += "NULL";
        if (i != array.getLength() - 1)
            obj += ", ";
    }

    obj += " ]";
    return obj;
}
*/
/*
template <>
Array<Shape>::Array(Array<Shape> &copy)
{
    array = new Shape *[copy.length]();
    this->length = copy.length;

    for (int i = 0; i < length; i++)
    {
        if (copy[i])
            array[i] = copy[i]->clone();
    }
}
*/
