#include<bits/stdc++.h>
using namespace std;

int dp[65][65];

int g(int n,int m)
{
	if(dp[n][m]!=0)return dp[n][m];
	if(n==m)return dp[n][m]=1;
	dp[n][m]=g(n,m+1)+(n-m);
	return dp[n][m];
}

int main()
{
	for(int i=1;i<=60;++i)
		g(i,1);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		cout<<dp[n][m]<<endl;
	}
	return 0;
}
