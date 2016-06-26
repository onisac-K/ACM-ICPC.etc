#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[70];

ll p(ll i, ll n)
{
	ll ans=1;
	for(int j=0;j<n;++j)ans*=i;
	//cout<<n<<' '<<ans<<endl;
	return ans;
}

int main()
{
	int n;
	dp[1]=1;
	for(int i=2;i<=64;++i)
	{
		dp[i]=INT_MAX;
		for(int j=1;j<i;++j)
		{
			if(j==63)continue;
			dp[i]=min(dp[i],2*dp[i-j]+p(2,j)-1);
		}
	}
	while(cin>>n)
	{
		cout<<dp[n]<<endl;
	}
} 
