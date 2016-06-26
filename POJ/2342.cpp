#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define mem(A,x) memset(A,x,sizeof(A));
#define N 6005

int dp[N][2];// 1 yes 0 no
int pa[N],vis[N];
int n;

void dfs(int r)
{
	if(vis[r]!=0)return ;
	vis[r]=1;
	for(int i=0;i<n;++i)
	{
		if(vis[i]==0&&pa[i]==r)
		{
			dfs(i);
			dp[r][1]+=dp[i][0];
			dp[r][0]+=max(dp[i][0],dp[i][1]);
		}
	}	
}

int main()
{
	while(cin>>n)
	{
		mem(dp,0);
		mem(pa,-1);
		mem(vis,0);
		for(int i=0;i<n;++i)scanf("%d",&dp[i][1]);
		int u,v;
		while(scanf("%d%d",&u,&v)!=EOF)
		{
			if(u==0&&v==0)break;
			u--;
			v--;
			pa[u]=v;
		}
		int root=-1;
		for(int i=0;i<n;++i)
		{
			if(pa[i]==-1)
			{
				root=i;
				break;
			}
		}
		dfs(root);
		int ans=max(dp[root][0],dp[root][1]);
		cout<<ans<<endl;
	}
	return 0;
} 
