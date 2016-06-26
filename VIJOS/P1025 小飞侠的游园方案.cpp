#include<bits/stdc++.h>
using namespace std;

int dp[105][1005]={0};

int main()
{
	int n,t;
	cin>>n>>t;
	int x,y;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		for(int j=t;j>=0;--j)
		{
			if(j-y>=0)dp[i][j]=max(dp[i-1][j],dp[i-1][j-y]+x);
			else dp[i][j]=dp[i-1][j];
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
} 
