#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int a[50005];


ll C(ll n)
{
	return n*(n-1)/2;
}

int main() {
    int n,k;
	char p[10];
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		int num=0;
		scanf("%s",p);
		
		int l=strlen(p);
		int flag=0;
		int f1=0,f2=0;
		for(int i=0;i<l;++i)
		{
			if(p[i]=='/')flag=1;
			else if(flag==0)
			{
				f1=f1*10+(p[i]-'0');
			}
			else 
			{
				f2=f2*10+(p[i]-'0');
			}
		}
		ll sum=0;
		ll u1=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			if(i>=k)u1+=a[i];
		}
		ll d=C(sum);
		//d+=sum;
		//cout<<d<<endl;
		if(a[n-1]>1)num=n*2;
		else num=n*2-1;
		ll u=0;
		for(int i=1;i<=n;++i)
		{
			//cout<<u<<endl;
			if(i+n>=k)
			for(int j=i;j<=n;++j)
			{
				if(i+j>=k)
				{
					//cout<<i<<' '<<j<<' ';
					//cout<<a[i]<<' '<<a[j]<<endl;
					if(i==j&&a[i]>1)u+=C(a[i]);
					else if(i!=j)u+=a[i]*a[j];
				}
			}
		}
		ll ans1=u*f1;
		ll ans2=f2*d;
		//cout<<u<<endl;
		//cout<<ans1<<' '<<ans2<<endl;
		ll q=__gcd(ans1,ans2);
		ans1/=q;
		ans2/=q;
		//cout<<ans1<<' '<<ans2<<endl;
		if(ans1==0||ans2==0)cout<<"Impossible"<<endl;
		else cout<<ans1<<'/'<<ans2<<endl;
		cout<<num<<endl;
		
	 } 
    return 0;
}
