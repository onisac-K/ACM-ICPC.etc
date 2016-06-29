#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1005];
ll a[1005];

int main()
{
	int n;
	while(cin>>n && n)
	{
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		memset(dp,0,sizeof(dp));
		ll ans=0;
		for(int i=1;i<=n;++i)
		{
			dp[i]=a[i];
			ans=max(ans,a[i]);
			for(int j=1;j<i;++j)
			{			
				if(a[i]>a[j])
				{
					dp[i]=max(dp[i],dp[j]+a[i]);
					ans=max(ans,dp[i]);
				}
			}
		}
		cout<<ans<<endl;
	}
}
