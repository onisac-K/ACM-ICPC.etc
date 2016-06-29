#include<iostream>
#include<cstdio>
using namespace std;

int dp[105][105];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
		{
			scanf("%d",&dp[i][j]);
		}
	}
	for(int i=n-1;i>=1;--i)
	{
		for(int j=1;j<=i;++j)
		{
			int k = max(dp[i+1][j],dp[i+1][j+1]);
			dp[i][j]+=k;
		}
	}
	cout<<dp[1][1]<<endl;
}

