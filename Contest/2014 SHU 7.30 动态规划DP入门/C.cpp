#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int va[1005],vo[1005];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,v;
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&v);
		for(int i=1;i<=n;++i)scanf("%d",&va[i]);
		for(int i=1;i<=n;++i)scanf("%d",&vo[i]);
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=v;++j)
			{
				if(j<vo[i])dp[i][j]=dp[i-1][j];
				else dp[i][j]=max(dp[i-1][j],dp[i-1][j-vo[i]]+va[i]);
			}
		}
		cout<<dp[n][v]<<endl;
	}
}
