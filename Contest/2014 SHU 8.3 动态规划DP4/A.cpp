#include<iostream>
#include<cstdio>
using namespace std;

int dp[105][105];
int a[105][105];
int dr[4][2]={1,0,-1,0,0,1,0,-1};
int n,m;

bool in(int i,int j)
{
	if(i>=0 && i<n && j<m && j>=0)return true;
	return false;
}

int dfs(int i,int j)
{
	if(dp[i][j])return dp[i][j];
	int ans = 0;
	int x,y;
	int flag=0;
	for(int k=0;k<4;++k)
	{
		x=i+dr[k][0];
		y=j+dr[k][1];
		if(in(x,y))
		{
			if(a[x][y]<a[i][j])
			{
				flag = 1;
				ans = max(ans,dfs(x,y)+1);
			}
		}
	}
	if(flag==0)return dp[i][j]=1;
	else return dp[i][j]=ans;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)scanf("%d",&a[i][j]);
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(dp[i][j]==0)dfs(i,j);
		}
	}
	int ans = 0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)ans=max(ans,dp[i][j]);
	}
	cout<<ans<<endl;
	return 0;
}

