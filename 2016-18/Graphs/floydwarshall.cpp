#include <iostream>
const int inf=1E9;

using namespace std;

int main()
{
 int n,i,j,k,d[100][100];

 cin >> n;

 for (i = 0; i < n; i++)
  for (j = 0; j < n; j++)
  {
   cin >> d[i][j];
   if (i == j)
    d[i][j] = min(d[i][j],0);
   if (d[i][j] == 1001)
    d[i][j]=inf;
  }

 for (k = 0; k < n; k++)
  for (i = 0; i < n; i++)
   for (j = 0; j < n; j++)
    if (d[i][k] < inf && d[k][j] < inf) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);

 for (i = 0; i < n; i++)
  if (d[i][i] < 0)
  {
    cout << "INCORRECT INPUT";
    return 0;
  }

 for (i = 0; i < n; i++)
 {
  for (j=0;j<n;++j)
   if (d[i][j]==inf) cout << "NO";
   else cout << d[i][j] << " ";
  cout << endl;
 }
}
