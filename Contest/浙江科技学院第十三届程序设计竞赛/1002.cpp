#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll x,int n)
{
	int num=0;
	ll y=x*x;
	while(y>0)
	{
		num++;
		y/=10;
	}
	num-=n;
	ll mod=1;
	if(num>0)while(num--)mod*=10;
	return (x*x)/mod;	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		ll x;
		cin>>n>>x;
		set<ll>s;
		ll y=f(x,n);
		//cout<<y<<endl;
		s.insert(x);
		ll ans=max(x,y);
		while(!s.count(y))
		{
			s.insert(y);
			y=f(y,n);
			//cout<<y<<endl;
			ans=max(ans,y);
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
