#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll Pow(ll a,ll n)     
{
		ll ans=1;
		while(n)
		{
			if(n&1)
			{
				ans=ans*a;
				ans%=mod;
			}
			a*=a;
			a%=mod;
			n>>=1;
		}
		ans%=mod;
		return ans;
}

ll mod_reverse(ll a, ll m){
		ll y=0,x=1,r=a%m, q, t, mm=m;//≥ı ºªØ
		if(r<0)r=r+m;
		while((m%r) != 0) {
			a=m; m=r;
			q= a/m; r=a % m;
			t=x; x=y-x*q; y=t;
		}
		if(r!=1) return 0;
		if(x<0) x=x+mm;
		return x;
}


int main()
{
	int n;
	while(cin>>n)
	{
		ll ans = 3*Pow(n,2)+Pow(n,3)+2*Pow(n,1);
		ans%=mod;
		ans = ans*mod_reverse(6,mod);
		ans%=mod;
		cout<<ans<<endl; 
	}
	return 0;
 } 
