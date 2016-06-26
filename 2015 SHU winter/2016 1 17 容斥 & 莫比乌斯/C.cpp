/*wrong answer*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ML LONG_LONG_MAX 
ll Pow(ll a,ll n)      
{
		ll ans=1;
		while(n)
		{
			if(n&1)ans=ans*a;
			a*=a;
			n>>=1;
			//cout<<ans<<endl;
			if(ans>ML||a>ML)return -1;
		}
		return ans;
}

ll num[100];

ll f(ll x,ll y,ll ans)
{
	ll q=Pow(x,y);
	if((q>ans||q==-1))return x-1;
	else if(q<ans&&Pow(x+1,y)!=-1&&Pow(x+1,y)<=ans)return x+1;
	return x;
}

int solve(int x)
{
	int i;	
	memset(num,0,sizeof(num));
	num[1]=x;
	if(x<=3)return x;
	for(i=2;i<=63;++i)
	{
		ll s=(ll)pow((double)x,1.0/i);
		//cout<<s<<endl;
		//cout<<f(s,i,x)<<endl;
		num[i]=f(s,i,x)-1;
		if(num[i]==0)break;
	}
	//for(int j=1;j<i;++j)cout<<num[j]<<endl;
	for(int j=i-1;j>0;--j)
	{
		for(int k=1;k<j;++k)
		{
			if(j%k==0)num[k]-=num[j];
		}
	}
	//cout<<num[1]<<endl;
	ll ans=num[1];
	for(int j=2;j<i;++j)ans+=(j*num[j]);
	return ans;
}

int main()
{
	//cout<<ML<<endl;
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0)break;
		//for(int i=0;i<10;++i)cout<<num[i]<<endl;
		cout<<solve(m)-solve(n-1)<<endl;
	}
}
