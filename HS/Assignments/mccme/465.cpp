#include <iostream>
using namespace std;

int main()
{
  int vertices, edges;
  cin >> vertices >> edges;
  int arr[vertices][vertices];

  for(int i = 0; i < vertices; i++)
    for(int j = 0; j < vertices; j++)
      arr[i][j] = 0;

  for(int i = 0; i < edges; i++)
  {
    int start, end;
    cin >> start >> end;
    arr[start-1][end-1] = 1;
    arr[end-1][start-1] = 1;
  }

  for(int i = 0; i < vertices; i++)
  {
    for(int j = 0; j < vertices; j++)
      cout << arr[i][j] << ' ';
    cout << endl;
  }

  return 0;
}
