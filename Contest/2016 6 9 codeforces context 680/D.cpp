#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005];
int n;
ll ans,num;

void solve(ll x)
{
	ans = 0;
	num = 0;
	for(int i=n;i>=1;--i)
	{
		ll k = x / a[i];
		//cout<<a[i]<<endl;
		num+=k;
		ans += k*a[i];
		x-= k*a[i];
	}
	//cout<<num<<' '<<ans<<endl;
}

int main()
{
	for(ll i=1;i<=100000;++i)
	{
		a[i]=i*i*i;	
	}
	ll x;cin>>x;
	for(n=100000;n>=1;--n)
	{
		if(a[n]<x)break;
	}
	n++;
	ll q,p;
	solve(x);
	q=num;
	p=ans;
	int cou=0;
	for(ll i=x-1;i>=1;i-=(q-1))
	{
		//cout<<i<<endl;
		solve(i);
		if(num>q)
		{
			q=num;
			p=ans;
			//cou=0;
		}
		else 
		{
			cou++;
		}	
		//cout<<q<<' '<<p<<endl;
		if(cou==10000)break;
	} 
	cout<<q<<' '<<p<<endl;
	return 0;
} 
