#include<iostream>
#include<cstdio>
using namespace std;

int dp1[13000],dp2[13000];

int main()
{
	int n,m;
	cin>>n>>m;
	int w,v;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&w,&v);
		for(int j=0;j<=m;++j)
		{
			if(j<w)
			{
				dp2[j]=dp1[j];
			}
			else 
			{
				dp2[j]=max(dp1[j],dp1[j-w]+v);
			}
		}
		for(int j=0;j<=m;++j)dp1[j]=dp2[j];
	}
	cout<<dp2[m]<<endl;
 } 
