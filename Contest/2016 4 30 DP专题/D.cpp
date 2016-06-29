#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int M = 2000;
int adj[maxn][maxn];
int dp[maxn][2],vis[maxn];
int n,m;

void dfs(int i)
{
	vis[i]=1;
	dp[i][0]=0*0+0;
	dp[i][1]=M*1+0;
	for(int j=0;j<n;++j)
	{
		if(vis[j]==0&&adj[i][j]==1)
		{
			dfs(j);
			dp[i][0]+=dp[j][1]+1;
			if(dp[j][0]<dp[j][1])
			{
				dp[i][1]+=dp[j][0]+1;
			}
			else dp[i][1]+=dp[j][1];
		}
	}
	
}

int  main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		int u,v;
		memset(adj,0,sizeof(adj));
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&u,&v);
			adj[u][v]=1;
			adj[v][u]=1;
		}
		memset(vis,0,sizeof(vis));
		
		int ans=0;
		for(int i=0;i<n;++i)
		{
			if(vis[i]==0)
			{
				dfs(i);
				ans+=min(dp[i][0],dp[i][1]);
			}
		}
		printf("%d %d %d\n",ans/M,m-ans%M,ans%M);
	}
	return 0;
}
/*
2
4 3
0 1 
1 2
2 3

5 4
0 1 0 2 0 3 0 4
*/
