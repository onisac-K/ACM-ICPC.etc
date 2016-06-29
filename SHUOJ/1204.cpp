#include<bits/stdc++.h>
using namespace std;
int n;
int dp[10005][4];
int mod = 7654321;



int main()
{

	cin>>n;
	dp[1][0]=1;
	for(int i =2;i<=n;++i)
	{
		dp[i][1]+=(dp[i-1][0]+dp[i-1][3]);
		dp[i][0]+=(dp[i-1][1]);
		dp[i][2]+=(dp[i-1][3]);
		dp[i][3]+=(dp[i-1][2]+dp[i-1][1]); 
		for(int j =0;j<=3;++j)dp[i][j]%=mod;
	}
	int ans = (dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3])%mod;
	cout<<ans<<endl;
} 
