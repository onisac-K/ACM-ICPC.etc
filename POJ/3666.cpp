#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long

ll a[2005];
ll dp[2005][2005];
ll b[2005];

ll ab(ll s){
	if(s<0)s*=-1;
	return s;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%I64d",&a[i]);
		b[i] = a[i];
	}
	sort(b+1,b+1+n);
	memset(dp,0x3f3f3f3f,sizeof(dp));
	for(int i=1;i<=n;++i)dp[1][i] = ab(a[1]-b[i]);
	for(int i=2;i<=n;++i){
		ll mini = 0x3f3f3f3f;
		for(int j=1;j<=n;++j){
			mini = min(mini,dp[i-1][j]);
			dp[i][j] = min(dp[i][j],mini+ab(a[i]-b[j]));
		}
	}
	ll ans = 0x3f3f3f3f;
	for(int i=1;i<=n;++i)ans = min(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}
