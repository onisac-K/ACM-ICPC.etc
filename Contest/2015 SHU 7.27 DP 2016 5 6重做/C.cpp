#include<bits/stdc++.h>
using namespace std;

int dp[15][100005];

int main()
{
	int n;
	while(cin>>n&&n)
	{
		int x,t;
		int maxt=0;	
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&x,&t);
			dp[x][t]++;
			maxt=max(maxt,t);
		}
		//cout<<dp[7][2]<<endl;
		for(t=maxt-1;t>0;--t)
		{
			for(int j=0;j<=10;++j)
			{
				if(j==0)dp[j][t]+=max(dp[1][t+1],dp[0][t+1]);
				else if(j==10)dp[j][t]+=max(dp[10][t+1],dp[9][t+1]);
				else
				{
					dp[j][t]+=max(max(dp[j][t+1],dp[j+1][t+1]),dp[j-1][t+1]);
				}
			}
		}
		//for()
		//cout<<dp[7][2]<<endl;
		int ans = max(dp[5][1],dp[6][1]);
		ans= max(ans,dp[4][1]);
		cout<<ans<<endl;
	}
	return 0;
}
