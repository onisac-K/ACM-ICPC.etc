#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll mx[62000];
ll Mx[62000];
ll mh[62000];
ll Mh[62000];
ll a[62000];
ll b[62000];
int n;

#define lowbit(i) (i&(-i))
ll bit[62000];
	
void add(int i,ll x)
{
//	if(bit[i])return ;
	while(i<=62000)
	{
		bit[i]+=x;
		i+=lowbit(i);
	}
}

ll query(int i)
{
	ll s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=lowbit(i);
	}
	return s;
} 

int main()
{

	while(cin>>n){
		memset(bit,0,sizeof(bit));
		ll sum = 0;
		for(int i=1;i<=n;++i){
			scanf("%I64d",&a[i]);
			b[i]=a[i];
		}	
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i){
			b[i]=lower_bound(a,a+n,b[i])-a+1;
		}
		for(int i=1;i<=n;++i){
			a[i] = b[i];
		}
		for(int i=1;i<=n;++i)b[i] = a[n-i+1];
		for(int i=1;i<=n;++i){
			mx[i] = query(a[i]-1);
			ll x = query(a[i]);
			Mx[i] = i-(x)-1;	
			add(a[i],1);
		}
		// mh 
		memset(bit,0,sizeof(bit));
		for(int i=1;i<=n;++i){
			mh[n-i+1] = query(b[i]-1);
			ll x = query(b[i]);
			Mh[n-i+1] = i-(x)-1;
			add(b[i],1);
		}
		//for(int i=1;i<=n;++i)cout<<mx[i]<<' ';cout<<endl;
		//for(int i=1;i<=n;++i)cout<<Mx[i]<<' ';cout<<endl;
		ll ans = 0,sum1 = 0, sum2 = 0;
		for(int i=1;i<=n;++i){
			sum1 += mx[i];
			sum2 += Mx[i];
			sum += mx[i]*Mx[i]+Mh[i]*mh[i]+mx[i]*mh[i]+Mx[i]*Mh[i];
		}
		//cout<<sum1<<' '<<sum2<<' '<<sum<<endl;
		ans = sum1*sum2-sum;
		ans = max(ans,0*1LL);
		cout<<ans<<endl;
	}
	return 0;
}
