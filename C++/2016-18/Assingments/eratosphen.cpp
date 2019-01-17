 #include <iostream>
 #include <vector>

 using namespace std;

 int main()
 {
   int n;
   cin >> n;
   vector <int> grate(n-1);
   for(int i=0; i < n-1; i++)
   {
     grate[i] = 2+i;
     cout << grate[i] << ' ';
   }
   cout << endl;
   for(int i=0; i < grate.size(); i++)
   {
     for(int j=i+1; j < grate.size(); j++)
     {
       if(grate[j] % grate[i] == 0)
       {
         grate.erase(grate.begin() + j);
       }
     }
     for(int i=0; i < grate.size(); i++)
     {
       cout << grate[i] << ' ';
     }
     cout << endl;
   }
   for(int i=0; i < grate.size(); i++)
   {
     cout << grate[i] << ' ';
   }
   cout << endl;
   return 0;
 }
