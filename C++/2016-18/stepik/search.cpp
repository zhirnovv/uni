#include <iostream>
using namespace std;

unsigned strlen(const char *str)
{
    const char* p = str;
    int length=0;
    while(*p != '\0')
    {
        length++;
        *p++;
    }
    return length;
}

int strstr(const char * text, const char * pattern)
{
  int text_size;
  text_size = strlen(text);
  int pattern_size;
  pattern_size = strlen(pattern);

  if (pattern_size == 0)
    return 0;

  if (pattern_size > text_size)
    return 0;

  for(int i = 0; i <= (text_size - pattern_size); i++)
  {
    k = 0;
    for(int j = 0; j < pattern_size; j++)
    {
      if(text[i+j] == pattern[j])
        k++:
      else break;
    }
    if (k == pattern_size) return i;
  }
  return -1;
}
