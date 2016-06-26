#include<bits/stdc++.h>
using namespace std;
vector<int>v[3005];
int s[3005];
int f[3005];
int ff[3005];
int dp[3005];

bool debug()
{
	for(int i=1;i<7;++i)cout<<dp[i]<<' ';
	cout<<endl;
//	for(int i=1;i<7;++i)cout<<s[i]<<' ';
	//cout<<endl;
}

void dfs(int a)
{
	debug();
	for(int i=0;i<v[a].size();++i)
	{
		dp[v[a][i]]=max(dp[v[a][i]],dp[a]+s[v[a][i]]);
		int k=s[a];
		s[a]=0;
		dfs(v[a][i]);
		s[a]=k;
	}
	return;
}



int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
	}
	for(int i=0;i<n;++i)
	{
		scanf("%d",&x);
		s[i+1]=x;
	}
	int a,p;
	cin>>a>>p;
	dp[a]=s[a];
	//s[a]=0;		
	dfs(a);
	int ans=0;
	for(int i=0;i<p;++i)
	{
		scanf("%d",&ff[x]);
	}
	for(int i=1;i<=n;++i)ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
 } 
