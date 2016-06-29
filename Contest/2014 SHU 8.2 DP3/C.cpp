#include<iostream>
#include<cstdio>
using namespace std;

double dp[100005];

int main()
{
	int n,m;
	cin>>n>>m;
	dp[1]=1;
	double ans = 1;
	for(int i=2;i<=m;++i)
	{
		dp[i]=dp[i-1]*(dp[i-1]-1.0/n)+(1-dp[i-1])*dp[i-1];
		ans += dp[i];
	}
	printf("%.15f\n",ans);
} 
