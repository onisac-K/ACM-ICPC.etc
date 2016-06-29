#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll getnum(int a,int n)
{
	ll s=0;
	for(int i=1;i<=n;++i)
	{
		s=s*10+a;
	}
	return s;
}

int main()
{
	int s,n;
	int f=1;
	while(cin>>s>>n)
	{
		ll ans=0;
		for(int i=1;i<=n;++i)
		{
			ans+=getnum(s,i);
		}
		printf("Case %d: %d\n",f++,ans); 
	}
	return 0;
}
