#include<iostream>
using namespace std;
#define ll long long

ll gcd(ll x, ll y)
{
	return y==0? x:gcd(y,x%y);
}

ll p(ll a,ll b)
{
	ll t=1;
	while(b)
	{
		if(b&1)t*=a;
		a*=a;
		b>>=1;
	}
	return t;
}

int main()
{
	int n,m;
	while(cin>>m>>n)
	{
		if(m==0&&n==0)break;
		ll ans=0;
		for(int i=0;i<n;++i)ans+=p(m,gcd(i,n));
		if(n%2==0)
		{
			ans+=(n/2)*(p(m,n/2)+p(m,n/2+1));
		}
		else ans+=n*(p(m,(n+1)/2));
		cout<<ans/(2*n)<<endl;
	}
	return 0;
}
