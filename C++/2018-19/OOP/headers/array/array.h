#ifndef ARRAY_H
#define ARRAY_H

class Array
{
  private:
    int *array;
    int size;

  public:
    Array();
    Array(int arraySize);
    ~Array();
    void resetSize(int newSize);
    void getItem();
    void setItem();
    int getSize();
};

#endif