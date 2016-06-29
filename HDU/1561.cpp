#include<bits/stdc++.h>
using namespace std;

vector<int> son[205];
int value[205];
int dp[205][205];
int mid[205][205];
int vis[205];
int n,m;

void dfs(int pa)
{
	if(vis[pa]==1)return ;
	vis[pa]=1;
	for(int i=0;i<son[pa].size();++i)
	{
		int so=son[pa][i];
		if(!vis[so])
		{
			dfs(so);
			for(int k=m;k>=0;--k)
			{
				for(int j=0;j<=k;++j)
				{
					mid[pa][k]=max(mid[pa][k],mid[pa][k-j]+dp[so][j]);
				}
			}
		}
	}
	for(int j=1;j<=m+1;++j)
		dp[pa][j]=mid[pa][j-1]+value[pa];
}

int main()
{
	while(cin>>n>>m && (n||m))
	{
		int a,b;
		for(int i=0;i<=n;++i)son[i].clear();
		
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&a,&b);
			son[a].push_back(i);
			value[i]=b;
		}
		value[0]=0;
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		memset(mid,0,sizeof(mid));
		dfs(0);
		cout<<dp[0][m+1]<<endl;
	}
} 
