#include<iostream>
#include<cstdio>
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
	int t;
	cin>>t;
	while(t--){
		int m;
		int n;
		cin>>m>>n;
		ll ans = 0;
		int a,b;
		for(int i=0;i<n;++i){
			scanf("%d%d",&a,&b);
			ans += Pow(a,b,m);
			ans %= m;
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
 
