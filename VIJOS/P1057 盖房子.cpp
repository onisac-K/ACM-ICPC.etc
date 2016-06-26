#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005]={0};

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&dp[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(dp[i][j]==0)continue;
			dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
			ans=max(ans,dp[i][j]);
		}
	}	
	/*for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}*/
	cout<<ans<<endl;
	return 0;
}
