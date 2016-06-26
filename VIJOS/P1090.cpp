#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[500005];
ll ans[500005];

int main()
{
	int n,k;
	cin>>n>>k;
	ll x;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&x);
		sum[i]=sum[i-1]+x;
	}
	int m=0;
	for(int i=1;i<=n;++i)
	{
		int mod = sum[i]%k;
		m=max(m,mod);
		ans[mod]++;
	}
	ll anw=ans[0];
	//for(int i=0;i<=m;++i)cout<<ans[i]<<' ';
	//cout<<endl;
	for(int i=0;i<=m;++i)
	{
		if(ans[i]>1)anw+=ans[i]*(ans[i]-1)/2;
		anw%=1234567;
	}
	cout<<anw<<endl;
	return 0;
} 
