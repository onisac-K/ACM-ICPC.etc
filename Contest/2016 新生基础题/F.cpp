#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int Max = INT_MAX;

int main()
{
	ll n;
	int f=1;
	while(cin>>n)
	{
		ll ans[100];
		ll cnt=1;
		ans[0]=n;
		ll q=n;
		while(n<Max)
		{
			n*=q;
			if(n>Max)break;
			ans[cnt++]=n;
		}
		if(cnt>5)cnt=5;
		printf("Case %d: ",f++);
		for(int i=0;i<cnt;++i)
		{
			if(i<cnt-1)
			{
				printf("%d, ",ans[i]);
			}
			else printf("%d\n",ans[i]);
		}
	}
	return 0;
}
