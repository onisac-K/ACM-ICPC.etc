#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll Pow(ll a,ll n,ll mod)      //ȡĤ�İ汾
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


int main()
{
	ll a,b,k;
	while(cin>>a>>b>>k)
	{
		ll c = a+b;
		a = a*Pow(2,k,c);
		b = b*Pow(2,k,c);
		a%=c;
		b%=c;
		cout<<min(a,b)<<endl;
	} 
	return 0;
}
