#include<bits/stdc++.h>
using namespace std;

int ma[505][505];
int a[505];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int aa,b;
	memset(ma,0x3f3f3f3f,sizeof(ma));
	
		for(int j=0;j<n-1;++j)
		{
			scanf("%d%d",&aa,&b);
			ma[aa][b]=1;
			ma[b][aa]=1;
		}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
			}
		}
	} 
	int ans = 0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(__gcd(a[i],a[j])==1)
			{
				ans += ma[i][j];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
