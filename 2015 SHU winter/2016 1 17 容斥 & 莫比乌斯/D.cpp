#include<bits/stdc++.h>
using namespace std;

#define ll long long

int a[15],m;
ll n,ans,cnt;

ll gcd(ll a, ll b)
{
	return b==0? a:gcd(b,a%b);
}

int dfs(int i,ll j,int k)
{
	ll l=a[i]/(gcd(a[i],j))*j;
	if(k&1)ans+=n/l;
	else ans-=n/l;
	for(int ii=i+1;ii<cnt;++ii)dfs(ii,l,k+1);
}

int main()
{
	while(cin>>n>>m)
	{
		ans=0;
		n--;
		cnt=0;
		int x;
		while(m--)
		{
			cin>>x;
			if(x!=0)a[cnt++]=x;
		}
		for(int i=0;i<cnt;++i)dfs(i,a[i],1);
		cout<<ans<<endl;
	}
	return 0;
}
