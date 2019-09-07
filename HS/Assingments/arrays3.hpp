#ifndef FILL_HPP
#define FILL_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void onetwo(int arr[], int size)
{
  for(int i=0; i < size; i+=2)
    arr[i] = 1;

  for(int i=1; i < size; i+=2)
    arr[i] = 2;

  for(int i=0; i<size; i++)
    cout << arr[i] << ' ';

  cout << endl;
}

void onetwothree(int arr[], int size)
{
  for(int i=0; i < size; i+=3)
    arr[i] = 1;

  for(int i=1; i < size; i+=3)
    arr[i] = 2;

  for(int i=2; i < size; i+=3)
    arr[i] = 3;

  for(int i=0; i<size; i++)
    cout << arr[i] << ' ';

  cout << endl;
}

void twoplustwo(int arr[], int size)
{
  for(int i=0; i < size; i++)
  {
    arr[i] = 2*(i+1);
    cout << arr[i] << ' ';
  }

  cout << endl;
}

void zerotwo(int arr[], int size)
{
  int add=1;

  for(int i=0; i < size; i+=2)
    arr[i] = 0;

  for(int i=1; i < size; i+=2)
  {
    arr[i] = pow(2, add);
    add++;
  }

  for(int i=0; i<size; i++)
    cout << arr[i] << ' ';

  cout << endl;
}

void xfivesix(int arr[], int size)
{
  int add=1;

  for(int i=0; i<size; i+=3)
  {
    arr[i]=add;
    add++;
  }

  for(int i=1; i<size; i+=3)
    arr[i]=5;

  for(int i=2; i<size; i+=3)
    arr[i]=6;

  for(int i=0; i<size; i++)
    cout << arr[i] << ' ';

  cout << endl;
}

void minusten(int arr[], int size)
{
  int sub=100;
  for(int i=0; i<size; i++)
  {
    arr[i] = sub;
    sub-=10;
    cout << arr[i] << ' ';
  }

  cout << endl;
}

void threeplusthree(int arr[], int size)
{
  for(int i=0; i < size; i++)
  {
    arr[i] = 3*(i+1);
    cout << arr[i] << ' ';
  }

  cout << endl;
}

void random(int arr[], int size)
{
  srand(time(0));
  for(int i=0; i<size; i++)
  {
    arr[i] = rand()%101 - 50;
    cout << arr[i] << ' ';
  }
  cout << endl;
}

#endif
