#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100005;

vector<int> g[N];
ll dp[100005];

int main()
{
	int n,m;
	cin>>n>>m;
	int u,v;
	for(int i=0;i<m;++i)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll ans=-1;
	for(int i=1;i<=n;++i)
	{
		dp[i]=1;
		int k=g[i].size();
		for(int j=0;j<k;++j)
		{
			if(i>g[i][j])
			{
				dp[i]=max(dp[i],dp[g[i][j]]+1);
			}
		}
		ans=max( ans,1LL*dp[i]*k );
	}
	cout<<ans<<endl;
	return 0;
}
