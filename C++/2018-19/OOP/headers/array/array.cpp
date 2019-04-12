#include "array.h"
#include <iostream>

Array::Array(int arraySize)
{
    std::cout << "Called parametrized array" << std::endl;
    if (arraySize < 0)
    {
        std::cout << "Throwing 301..." << std::endl;
        throw 301;
    }
    size = arraySize;
    array = new int[arraySize];
}

Array::~Array()
{
    std::cout << "Called destructor" << std::endl;
    size = 0;
    delete[] array;
}

Array::Array()
{
    std::cout << "Called default constructor" << std::endl;
    size = 0;
    array = NULL;
}

void Array::resetSize(int newSize)
{
    delete[] array;
    size = newSize;
    array = new int[newSize];
}

int Array::getSize()
{
    return size;
}

void Array::getItem()
{
    int index;
    std::cout << "Enter index: ";
    std::cin >> index;
    if (index < 0 || index > size)
    {
        std::cout << "Throwing 302..." << std::endl;
        throw 302;
    }
    std::cout << array[index] << std::endl;
}

void Array::setItem()
{
    int index;
    std::cout << "Enter index: ";
    std::cin >> index;
    if (index < 0 || index > size)
    {
        std::cout << "Throwing 302..." << std::endl;
        throw 302;
    }
    int value;
    std::cout << "Enter value: ";
    std::cin >> value;
    array[index] = value;
}
