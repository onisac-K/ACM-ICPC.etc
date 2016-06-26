#include <bits/stdc++.h>
using namespace std;

int G[105][105];
int dp[205][105];
int a[205];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(G,0,sizeof(G));
		memset(dp,0x3f3f3f,sizeof(dp));
		int n1,n2;
		cin>>n1>>n2;
		int u,v;
		for(int i=0;i<n2;++i)
		{
			scanf("%d%d",&u,&v);
			G[u][v]=1;
			G[v][u]=1;
		}
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n1;++i)dp[0][i]=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n1;++j)
			{
				for(int k=1;k<=n1;++k)
				{
					if(j==k||G[j][k]==1)dp[i][k]=min(dp[i][k],dp[i-1][j]+(k!=a[i]));
					//dp[i][k]=min(dp[i][k],dp[i-1][j]+1);
				}
			}
		}
		/*for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n1;++j)cout<<dp[i][j]<<' ';
			cout<<endl;
		}*/
		cout<<dp[n][a[n]]<<endl;
	}
	return 0;
}
/*
2
7 9
1 2
2 3
2 4
2 6
3 4
4 5
5 6
7 4
7 5
9 1 2 2 7 5 5 5 7 4
7 9
1 2
2 3
2 4
2 6
3 4
4 5
5 6
7 4
7 5
9 1 2 2 6 5 5 5 7 4
*/
