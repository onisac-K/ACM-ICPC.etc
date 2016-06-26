#include<bits/stdc++.h>
using namespace std;

int a[1005];
int dp[1005];

int main()
{
	int n;
	while(cin>>n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<i;++j)
			{
				if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1);
				ans=max(ans,dp[i]);
			}
		}
		cout<<ans<<endl;
	}
}
