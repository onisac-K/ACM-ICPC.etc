#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*	set°æ  48ms 
int main()
{
	ll m=1;
	set<ll>s;
	s.insert(1);
	int i;
	for(i=1;m<1000000000;++i)
	{
		m+=i;
		s.insert(m);
	}
	cout<<i<<endl;
	int n;
	scanf("%d",&n);
	int x;
	while(n--)
	{
		scanf("%d",&x);
		if(s.count(x))printf("2\n");
		else printf("3\n");
	}
	return 0;
}
*/	
/* ¶þ·Ö 4ms */
ll num[50000];
int main()
{
	ll m=1;
	int i;
	int f=1;
	num[0]=1;
	for(i=1;m<1000000000;++i)
	{
		m+=i;
		num[f++]=m;
	}
	int n;
	cin>>n;
	ll x;
	while(n--)
	{
		scanf("%lld",&x);
		int l=0,r=f;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(num[mid]>x)r=mid-1;
			else if(num[mid]<x)l=mid+1;
			else if(num[mid]==x)
			{
				l=mid;
				break;
			}
		}
		if(num[l]==x||num[l+1]==x||num[l-1]==x)printf("2\n");
		else printf("3\n");
	}
	return 0;
}
