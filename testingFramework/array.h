#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>
#include <string>

#include <iostream>

using namespace std;

template <class T>
class Array
{
public:
    Array(int length);
    Array(Array<T> &copy);
    ~Array();

    void deleteAll();
    void increaseSizeBy(int increaseBy);
    void setLength(int newLength);

    T *&operator[](int i);
    const T *const &operator[](int i) const;
    T *getIndex(int i);

    Array<T> &operator=(const Array<T> &rhs);
    bool operator==(const Array<T> &rhs) const;

    int getLength() const;
    void insertNewItem(T &newItem);
    void insert(T item);

private:
    T **array;
    int length;
};

class Shape;
std::string to_string(Array<Shape> &array);

// Explicit specialization declaration (not definition)
template <>
Array<Shape>::Array(Array<Shape> &copy);

// All template function definitions must be in the header.
template <class T>
Array<T>::Array(int length)
{
    array = new T *[length]();
    this->length = length;
}

template <class T>
Array<T>::Array(Array<T> &copy)
{
    array = new T *[copy.length]();
    this->length = copy.length;

    for (int i = 0; i < length; i++)
    {
        if (copy.array[i])
            array[i] = new T(*copy.array[i]);
        else
            array[i] = nullptr;
    }
}

template <class T>
Array<T>::~Array()
{
    deleteAll();
    delete[] array;
}

template <class T>
void Array<T>::deleteAll()
{
    for (int i = 0; i < length; i++)
    {
        if (array[i])
            delete array[i];
    }
}

template <class T>
void Array<T>::increaseSizeBy(int increaseBy)
{
    if (increaseBy > 0)
    {
        int newLength = length + increaseBy;
        T **n_array = new T *[newLength]();

        for (int i = 0; i < length; i++)
        {
            n_array[i] = array[i];
        }

        delete[] array;
        array = n_array;
        length = newLength;
    }
    else
    {
        throw out_of_range("Array cannot have its size increased by a negative number.");
    }
}

template <class T>
void Array<T>::setLength(int newLength)
{
    if (newLength > 0)
    {
        deleteAll();
        delete[] array;
        array = new T *[newLength]();
        length = newLength;
    }
    else
    {
        throw out_of_range("Array length must be greater than 0.");
    }
}

template <class T>
T *Array<T>::getIndex(int i)
{
    if (i >= 0 && i < length)
    {
        return array[i];
    }
    else
    {
        throw out_of_range("Array index is out of bounds.");
    }
}

template <class T>
T *&Array<T>::operator[](int i)
{
    if (i >= 0 && i < length)
    {
        return array[i];
    }
    else
    {
        throw out_of_range("Array index is out of bounds.");
    }
}

template <class T>
const T *const &Array<T>::operator[](int i) const
{
    if (i >= 0 && i < length)
    {
        return array[i];
    }
    else
    {
        throw out_of_range("Array index is out of bounds.");
    }
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    deleteAll();
    delete[] array;

    this->length = rhs.length;
    array = new T *[length]();

    for (int i = 0; i < rhs.length; i++)
    {
        if (rhs.array[i])
        {
            array[i] = new T(*rhs.array[i]);
        }
        else
        {
            array[i] = nullptr;
        }
    }

    return *this;
}

template <class T>
bool Array<T>::operator==(const Array<T> &rhs) const
{
    if (length != rhs.length)
    {
        return false;
    }

    for (int i = 0; i < rhs.length; i++)
    {
        if (array[i] == nullptr && rhs.array[i] == nullptr)
        {
            continue;
        }
        if (array[i] == nullptr || rhs.array[i] == nullptr || !(*array[i] == *rhs.array[i]))
        {
            return false;
        }
    }

    return true;
}

template <class T>
int Array<T>::getLength() const
{
    return length;
}

template <class T>
void Array<T>::insertNewItem(T &newItem)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == nullptr)
        {
            array[i] = new T(newItem);
            return;
        }
    }

    increaseSizeBy(1);
    array[length - 1] = new T(newItem);
}

template <class T>
void Array<T>::insert(T item)
{
    insertNewItem(item);
}

// These specializations and non-template functions must be moved to a .cpp file.
// template <>
// Array<Shape>::Array(const Array<Shape> &copy);
// string to_string(Array<Shape> array);

#endif