#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 6005;

int dp[N][2];
int vis[N];
int pa[N];
int n;

void dfs(int i)
{
	//cout<<i<<endl;
	if(vis[i])return ;
	vis[i]=1;
	for(int j=0;j<n;++j)
	{
		if(pa[j]==i&&vis[j]==0)
		{
			dfs(j);
			dp[i][0]+=max(dp[j][1],dp[j][0]);
			dp[i][1]+=dp[j][0];
		}
	}
}

int main()
{
	cin>>n;
	memset(pa,-1,sizeof(pa));
	for(int i=0;i<n;++i)scanf("%d",&dp[i][1]) ;
	int u,v;
	for(int i=0;;++i)
	{
		scanf("%d%d",&u,&v);
		u--;
		v--;
		if(u==-1&&v==-1)break;
		pa[u]=v;
	}
	for(int i=0;i<n;++i)
	{
		if(pa[i]==-1)
		{
			dfs(i);
			//cout<<123<<endl;
		}
	}
	int ans=0;
	for(int i=0;i<n;++i)ans=max(dp[i][1],max(ans,dp[i][0]));
	cout<<ans<<endl;
	return 0;
 } 
