#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int dp[35][3];

int main()
{
	int t,w;
	cin>>t>>w;
	int s;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=t;++i)
	{
		scanf("%d",&s);
		for(int j=w+1;j>=1;--j)
		{
			dp[j][s]=max(dp[j][s]+1,dp[j-1][3-s]+1);
			//dp[j][3-s]
		}
		//for(int j=w+1;j>=1;--j)cout<<dp[j][1]<<' '<<dp[j][2]<<endl;
	}
	int ans = 0;
	for(int i=1;i<=w+1;++i)ans = max(dp[i][2],max(ans,dp[i][1]));
	cout<<ans<<endl;
	return 0;
}
