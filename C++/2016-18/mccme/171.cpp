#include <iostream>

using namespace std;

#define INF 1E9
int m[101][101], res[101][101];

void floyd(int n)
{
  int i, j, k;
  for(k = 0; k < n; k++)
    for(i = 0; i < n; i++)
      for(j = 0; j < n; j++)
        if ((m[i][k] < INF) && (m[k][j] < INF))
        {
          if (m[i][k] + m[k][j] < m[i][j])
            m[i][j] = m[i][k] + m[k][j];
          if (m[i][j] < -INF)
            m[i][j] = -INF;
        }
}

int main()
{
  int n, i, j, k;
  cin >> n;
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
    {
        cin >> m[i][j];
        if ((m[i][j] == 0) && (i != j))
          m[i][j] = INF;
    }
  floyd(n);

  for(i = 0; i < n; i++)
      for(j = 0; j < n; j++)
      {
          if (m[i][j] == INF)
            res[i][j] = 0;
          else
          {
            res[i][j] = 1;
            for(k = 0; k < n; k++)
              if ((m[k][k] < 0) && (m[i][k] < INF) && (m[k][j] < INF))
                  res[i][k] = res[i][j] = res[k][j] = 2;
          }
        }

  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
      cout << res[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
