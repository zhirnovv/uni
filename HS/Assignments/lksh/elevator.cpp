#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector< vector<int> > matrix, int start)
{
  vector<bool> visited(matrix.size(), false);
  queue<int> Q;

  Q.push(start);
  visited[start] = true;
  int count = 1;

  while(!Q.empty())
  {
    int top = Q.front();
    Q.pop();

    for (int i = 0; i < matrix.size(); ++i)
    {
        if(matrix[top][i] != 0 && (! visited[i]) )
        {
            Q.push(i);
            visited[i] = true;
            count++;
        }
    }
}
  return count;
}

int main()
{
  int count = 0, size, start;
  cin >> size >> start;
  vector< vector<int> > matrix;
  for(int i = 0; i < size; i++)
  {
    int cap;
    cin >> cap;

    for(int j = 0; j < cap; j++)
      {
        int reach;
        cin >> reach;
        matrix[i][reach] = 1;
        matrix[reach][i] = 1;
      }
  }

  for(int i = 0; i < size; i++)
    {
      for(int j = 0; j < size; j++)
        cout << matrix[i][j];
      cout << endl;
    }
}
