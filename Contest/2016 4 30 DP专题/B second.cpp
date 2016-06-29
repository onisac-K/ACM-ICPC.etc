#include<bits/stdc++.h>
using namespace std;

int dp[105][105];
int a[105];
int vis[105][105];
int sum[105];
int n;

int dfs(int l,int r)
{
	//cout<<dp[l][r]<<endl;
	if(l>r)return 0;
	if(dp[l][r]!=0)return dp[l][r];
	int ans=-10000000 ;// ±¾À´ÊÇ-10000000 
	for(int i=l;i<=r;++i)
	{
		ans=max(ans,sum[r]-sum[i-1]-dfs(l,i-1));
		ans=max(ans,sum[i]-sum[l-1]-dfs(i+1,r));
	}
	return dp[l][r]=ans;
}

int main()
{
	while(cin>>n&&n)
	{
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<=n;++j)dp[i][j]=0;
		}
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			sum[i]=a[i]+sum[i-1];
			dp[i][i]=a[i];
		}
		cout<<dfs(1,n)<<endl;
	}
} 
/*
4
4 -10 -20 7
4
1 2 3 4
0
*/
