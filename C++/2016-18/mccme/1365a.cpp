#include <iostream>
#include <queue>
using namespace std;

struct node
{
  int i;
  int j;
  char direction;
  node(const int i, const int j, const char direction)
		: i(i)
		, j(j)
		, direction(direction)
	{}
};


int main()
{
  int length, width, i1, j1, i2, j2;
  cin >> length >> width >> i1 >> j1 >> i2 >> j2;

  char landscape[length+2][width+2];
  for(int i=0; i < length+2; i++)
    for(int j=0; j < width+2; j++)
      landscape[i][j] = '#';
  for(int i=1; i <= length; i++)
    for(int j=1; j <= width; j++)
      cin >> landscape[i][j];
  if(landscape[i1][j1] == '#')
    return 0;

  int distance[length+2][width+2];
  for(int i=0; i < length+2; i++)
    for(int j=0; j < width+2; j++)
      distance[i][j] = -1;

  queue <node> path;
  path.push(node(i1, j1, ' '));

  return 0;
}
