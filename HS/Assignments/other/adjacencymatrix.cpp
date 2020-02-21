#include <iostream>
#include <vector>
using namespace std;

struct connection
{
  int start;
  int end;
};

int main()
{
  int vertices, edges;
  cin >> vertices >> edges;
  vector<connection> edgeConnections(edges);

  int adjacencyTable[vertices][vertices];
  for(int i=0; i < vertices; i++)
    for(int j=0; j < vertices; j++)
        adjacencyTable[i][j] = 0;

  for(int i=0; i < edges; i++)
  {
    cin >> edgeConnections[0].start >> edgeConnections[0].end;
  }

  for(int i=0; i < vertices; i++)
    for(int j=0; j < vertices; j++)
      if (edgeConnections[i].start == i && edgeConnections[j].end == j)
        adjacencyTable[i][j] = 1;

  for(int i=0; i < vertices; i++)
  {
    for(int j=0; j < vertices; j++)
      cout << adjacencyTable[i][j];
    cout << endl;
  }
  return 0;      
}
