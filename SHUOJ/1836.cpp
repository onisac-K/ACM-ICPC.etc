#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int n,a,b,c;
	while(cin>>n>>a>>b>>c)
	{
		ll ans=0;
		int k,k1,k2;
		for(int i=1;i*2<=n&&i<=b;i+=2)
		{
			k=n-2*i;
			if(k>a+c*5)continue;
			k1=min(k/5,c);
			if(k1&1)k1--;
			k2=max(k-a,0);
			k2=(k2+4)/5;
			if(k2&1)k2++;
			ans+=(k1-k2)/2+1;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
