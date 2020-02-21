#include <iostream>
using namespace std;
const int N=102;
int a[N][N];
int main()
{
	int i,j,k,b,c,ans=10000000,ans1,ans2,ans3,n;
	cin>>n;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			cin>>a[i][j];
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			for(k=1;k<=n;++k)
				if(i!=j && j!=k && i!=k)
				{
					b=a[i][j]+a[j][k]+a[k][i];
					if(b<ans)
					{
						ans1=i;
						ans2=j;
						ans3=k;
						ans=b;
					}
				}
	cout<<ans1<<" "<<ans2<<" "<<ans3;
	return 0;
}
