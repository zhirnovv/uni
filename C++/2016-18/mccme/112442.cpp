#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string,int>L;
    int a,n;
    string a1,S,s1,s2,s3;
    cin>>a1;
    cin>>n;
    for (int i=0;i<n;i++)
    {
      cin>>s1>>s2>>s3;
      S=s1+" "+s2+" "+s3;
      if(s1[0]==a1[0]&&a1[1]==s2[0]&&a1[2]==s3[0])
           L[S]++;
    }

    map<string,int>::iterator k, it;
    int m, i, l=L.size();
    for(i=0;i<l;i++)
    {
      m=0;
      for (k=L.begin();k!=L.end();k++)
        if(k->second>m)
        {
             m=k->second;
             S=k->first;
             it=k;
        }
       cout<<S<<" "<<m<<endl;
       L.erase(it);
    }
    return 0;
}
 
