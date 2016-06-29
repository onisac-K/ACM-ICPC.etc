#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int dp[1000005];
int a[25];

int main()
{
	int n,b;
	while(cin>>n>>b)
	{
		int ans = 99999999;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=b;++j)
			{
				if(dp[j]+a[i]>=b)
				{
					ans=min(ans,dp[j]+a[i]-b);
				}
			}
			for(int j=b;j>=a[i];--j)
			{
				dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
 
