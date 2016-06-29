/*wrong answer*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll fro[100005];
ll h[100005];
ll sum[100005];

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		memset(sum,0,sizeof(sum));
		for(int i=0;i<n;++i)
			scanf("%lld",&h[i]);
		sort(h,h+n);
		for(int i=0;i<n;++i)
		{
			if(h[i]%3==0)fro[i]=h[i]/3;
			else fro[i]=(h[i]/3+1);
			sum[0]+=fro[i];
			sum[0]%=mod;
		}
		int s=0;
		for(int i=1;i<=m;++i)
		{
			int num=0;
			if(h[s]<=0){
				s++;
				continue;
			}
			if(h[s]%3!=0)
			{
				sum[i]=sum[i-1]-1;
				h[s]-=2;
				fro[s]-=1;
				if(h[s]<=0)s++;
			}
			else if(h[s]%3==0)
			{
				sum[i]=sum[i-1];
				h[s]-=2;
			}
			/*if((h[s]-fro[s]*3+3)%2==0)num=(h[s]-fro[s]*3+3)/2;
			else num=(h[s]-fro[s]*3+3)/2+1;
			//cout<<num<<endl;
			if(1==num)
			{
				sum[i]=sum[i-1]-1;
				fro[s]--;
				if(h[s]-2<=0)s++;
				else h[s]-=2;
			}
			else if(1<num)
			{
				h[s]-=2;
				sum[i]=sum[i-1];
			}*/
		}
		//for(int i=0;i<=m;++i)cout<<sum[i]<<endl;
		ll ans = 0;
		for(int i=0;i<=m;++i)
		{
			ans+=sum[i];
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;	
}
