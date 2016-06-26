#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[18]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int b[18]={6,10,14,15,21,22,26,33,34,35,38,39,46,51,55,57,58};
int main()
{
	ll n;
	while(cin>>n)
	{
		ll ans=0;
		ll f=0;
		for(int i=0;i<17;++i){
			f=pow((double)n,1.0/a[i]);
			if(pow(f+1,a[i])<=n)f++;
			ans+=f;
		}
		for(int i=0;i<17;++i)
		{
			f=pow((double)n,1.0/b[i]);
			if(pow(f+1,b[i])<=n)f++;
			ans-=f;
		}
		//30 42
		f=pow((double)n,1.0/30);
		if(pow(f+1,30)<=n)f++;
		ans+=f;
		f=pow((double)n,1.0/42);
		if(pow(f+1,42)<=n)f++;
		ans+=f;
		cout<<ans-1<<endl;
	}
	
	
	
	return 0;
}
