#include<bits/stdc++.h>
using namespace std;

int vis[2][205];
int aa[205][205];
int dp[205][205];
int m,r;
int a,b;

void dfs(int s,int i)
{
	if(vis[s][i]==1)return;
	vis[s][i]=1;
	if(s==0)
	{
		for(int j=1;j<=m;++j)
		{
			if(vis[1][j])continue;
			if(aa[i][j])
			{
				b++;
				dfs(1,j);
			}
		}
	}
	else 
	{
		for(int j=1;j<=m;++j)
		{
			if(vis[0][j])continue;
			if(aa[j][i])
			{
				a++;
				dfs(0,j);
			}
		}
	}
}

void p()
{
	for(int j=m/2;j>=a;--j)
	{
		for(int k=m/2;k>=b;--k)
		{
			dp[j][k]=max(dp[j][k],dp[j-a][k-b]);
		}
	}
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(aa,0,sizeof(aa));
		memset(dp,0,sizeof(dp));		
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&m,&r);
		int u,v;
		for(int i=0;i<r;++i)
		{
			scanf("%d%d",&u,&v);
			aa[u][v]=1;
		}
		dp[0][0]=1;
		for(int i=1;i<=m;++i)
		{
			if(vis[0][i])continue;
			a=1; 
			b=0;
			dfs(0,i);
			//cout<<"a  b"<<a<<' '<<b<<endl;
			p();
			/*for(int j=a;j<=m/2;++j)
			{
				for(int k=b;k<=m/2;++k)
				{
					dp[j][k]=max(dp[j][k],dp[j-a][k-b]);
				}
			}*/
		}
		for(int i=1;i<=m;++i)
		{
			if(vis[1][i])continue;
			a=0;
			b=1;
			dfs(1,i);
			p();
			//cout<<"a  b"<<a<<' '<<b<<endl;
			/*for(int j=a;j<=m/2;++j)
			{
				for(int k=b;k<=m/2;++k)
				{
					dp[j][k]=max(dp[j][k],dp[j-a][k-b]);
				}
			}*/
		}
		int ans = 0;
		for(int i=m/2;i>=0;--i)
		{
			if(dp[i][i])
			{
				ans = i;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
