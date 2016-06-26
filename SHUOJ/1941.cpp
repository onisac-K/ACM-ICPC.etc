#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll Pow(ll a,ll n,ll mod)      //取膜的版本
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
		ll y=0,x=1,r=a%m, q, t, mm=m;//初始化
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

int d[1000];


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,q;
		ll ans=1,cnt=1;
		memset(d,0,sizeof(d));
		vector<int>a; 
		scanf("%d%d%d",&n,&m,&q);
		int p=n-m+1;
		int x=q;
		for(int j=2;j*j<=x;++j)
		{
			if(x%j==0)
			{
				while(x%j==0)x/=j;
				a.push_back(j);
			}
		}
		if(x!=1)a.push_back(x);
		int ln=a.size();
		//cout<<ln<<endl;
		//cout<<ln<<endl;
		/*for(int i=0;i<ln;++i)cout<<a[i]<<' ';
		cout<<endl;
		for(int i=0;i<ln;++i)cout<<d[i]<<' ';
		cout<<endl;*/
		for(int i=p;i<=n;++i)
		{
			x=i;
			for(int j=0;j<ln;++j)
			{
				while(x%a[j]==0)
				{
					x/=a[j];
					d[j]++;
				}
			}
			ans=(ans*x)%q;
		}
		/*for(int i=0;i<ln;++i)cout<<d[i]<<' ';
		cout<<endl;*/
		
		for(int i=2;i<=m;++i)
		{
			x=i;
			for(int j=0;j<ln;++j)
			{
				while(x%a[j]==0)
				{
					x/=a[j];
					d[j]--;
				}	
			}
			cnt=(cnt*x)%q;
		}
		//cout<<ans<<' '<<cnt<<endl;
		/*for(int i=0;i<ln;++i)cout<<d[i]<<' ';
		cout<<endl;*/
		for(int i=0;i<ln;++i)
		{
			ans=(ans*Pow(1LL*a[i],1LL*d[i],1LL*q))%q;
		}
		//cout<<"ans: "<<ans<<"   "<<"cnt: "<<cnt<<endl;
		//cout<<mod_reverse(cnt,q)<<endl;
		ans=ans*mod_reverse(cnt,q);
		
		
		printf("%lld\n",ans%q);
	}
	return 0; 
}


