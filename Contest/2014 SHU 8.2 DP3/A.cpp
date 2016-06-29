#include<bits/stdc++.h>
using namespace std;

int dp[40000];

int main()
{
	int n;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=3;++i)
	{
		for(int j=1;j<=32768;++j)
		{
			dp[j]+=dp[j-i];
		}
	}
	while(cin>>n)cout<<dp[n]<<endl;
}
