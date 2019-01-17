#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   int n;
   cin >> n;
   int d[n];
   int b[n];
   int memory[n];

   for(int i = 0; i < n; i++)
   {
     cin >> d[n];
   }

   b[1] = d[1];
   memory[1] = 1;

   int k;
   int max = d[1];
   int length=1;

   for(int j = 2; j <= n; j++)
   {
     b[j] = b[j-1] + d[j];
     memory[j] = b[j-1];

     if(b[j] > max)
     {
       max = d[j];
       k = j;
     }
   }
   cout << max;
   return 0;
}
