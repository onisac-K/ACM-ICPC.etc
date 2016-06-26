#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ml;

ll gcd(ll x, ll y)
{
	return y==0? x:gcd(y,x%y);
}

ll fpow(ll x, ll y)
{
	ll t=1;
	while(y)
	{
		if(y&1)
		{
			t*=x;
			t%=ml;
		}
		x*=x;
		x%=ml;
		y>>=1;	
	}
	t%=ml;
	return t;
}

ll rmod(ll a , ll m)
{
	ll y=0,x=1,r=a%m,q,t,mm=m;
	if(r<0)r+=m;
	while((m%r)!=0)
	{
		a=m;m=r;
		q=a/m;r=a%m;
		t=x;x=y-x*q;y=t;
	}
	if(r!=1)return 0;
	if(x<0)x+=mm;
	return x;
}

int main()
{
	ll n,a;
	while(cin>>n>>a>>ml)
	{
		ll k=0;
		for(int i=0;i<=n-1;++i)
		{
			k+=(fpow(a,gcd(1LL*i,n)));
			k%=ml;
		}
		ll p=rmod(n,ml);
		cout<<((p*k)%ml)<<endl;
	}
	return 0;
} 
