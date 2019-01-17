#ifndef MAX_HPP
#define MAX_HPP

int maxeven(int arr[], int size)
{
  int maximum=0;
  for(int i = 1; i < size; i+=2)
      if (arr[i] > maximum)
        maximum = arr[i];
  return maximum;
}

int minodd(int arr[], int size)
{
  int minimum = 2147483647;
  for(int i=0; i < size; i+=2)
    if (arr[i] < minimum)
      minimum = arr[i];
  return minimum;
}

int posnumber(int arr[], int size)
{
  int number = 0;
  for(int i=0; i<size; i++)
    if(arr[i]>0)
      number++;
  return number;
}

int fproduct(int arr[], int size)
{
  int temp=1;
  for(int i=0; i<5; i++)
    temp *= arr[i];
  return temp;
}

int negsum(int arr[], int size)
{
  int sum=0;
  for(int i=0; i<size; i++)
    if(arr[i]<0)
      sum += arr[i];
  return sum;
}

#endif
