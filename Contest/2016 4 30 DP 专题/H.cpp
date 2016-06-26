#include<bits/stdc++.h>
using namespace std;
#define CLR(x) memset(x,0,sizeof(x))
int a[10005];
int b[10005];
int dp[10005];
int dp2[10005];

void debug(int n)
{
	for(int i=1;i<=n;++i)cout<<dp[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;++i)cout<<dp2[i]<<' ';
	cout<<endl<<endl;
}

int main()
{
	int n;
	while(cin>>n)
	{
		CLR(dp);CLR(dp2);
		CLR(b);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		int L = 1 , L1 = 1;
		for(int i=1;i<=n;++i)
		{
			if(a[i]>b[L-1])
			{
				b[L]=a[i];
				dp[i]=L++;				
			}
			else {
				int l=1,r=L;
				while(l<=r)
				{
					int mid=(l+r)/2;
					if(b[mid]<a[i])l=mid+1;
					else r=mid-1;
				}
				b[l]=a[i];
				dp[i]=l; 
			}
		}
		CLR(b);
		for(int i=n;i>0;--i)
		{
			if(a[i]>b[L1-1])
			{
				b[L1]=a[i];
				dp2[i]=L1++;				
			}
			else {
				int l=1,r=L1;
				while(l<=r)
				{
					int mid=(l+r)/2;
					if(b[mid]<a[i])l=mid+1;
					else r=mid-1;
				}
				b[l]=a[i];
				dp2[i]=l; 
			}
		}
		//debug(n);
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			
			ans=max(ans,min(dp[i],dp2[i])*2-1);
			
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}
