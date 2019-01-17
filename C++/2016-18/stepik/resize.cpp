#include <iostream>
#include <new>

using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size)
{
  char * new_str = new char[new_size];

  for(int i = 0; i < size && i < new_size; i++)
    new_str[i] = str[i];

  delete [] str;

  return new_str;
}

int main()
{
  int new_size;
  cin >> new_size;

  int size = 0;
  const char input[] = "Hello, World!";

  while(input[size])
    size++;

  char * str = new char[size];
  for(int i = 0; i < size; i++)
    str[i] = input[i];

  cout << resize(str, size, new_size);
  return 0;
}
