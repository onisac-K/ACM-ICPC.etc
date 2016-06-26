#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		ll n,q;
		scanf("%d%d",&n,&q);
		ll x;
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&x);
			if(x&1)a[i]=a[i-1]+1;
			else a[i]=a[i-1];
		}
		ll y;
		for(int i=0;i<q;++i)
		{
			scanf("%lld%lld",&x,&y);
			//cout<<a[y]-a[x]<<endl;
			printf("%lld\n",((y-x+1)-(a[y]-a[x-1]))*(a[y]-a[x-1]));
		}
	}
	return 0;
} 
