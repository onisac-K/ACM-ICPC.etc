#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 4294967296
ll dp[105];

int main()
{
	ll n,m;
	cin>>n>>m;
	dp[1]=m;
//	cout<<dp[1]<<endl;
	ll ans = m; 
	for(int i=2;i<=n;i++)
	{
		if(i%2==0)dp[i]=((dp[i-1]*m)%mod-dp[i/2]+mod)%mod;
		else dp[i]=dp[i-1]*m;
		cout<<dp[i]<<endl;
		dp[i]%=mod;
		ans+=dp[i];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
} 
