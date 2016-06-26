#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
 
ll Pow(ll a,ll n)      //ȡĤ�İ汾
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
	int n;
	while(cin>>n)
	{
		if(n==1)cout<<1<<endl;
		else {
			ll ans ;
			ans = Pow(3,n-1);
			cout<<ans<<endl;
		}	
	}
	return 0;
}
