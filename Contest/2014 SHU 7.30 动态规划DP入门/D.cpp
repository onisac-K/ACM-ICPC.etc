#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int a[1005];

int main()
{
	int n;
	while(cin>>n && n)
	{
		int ma=0,k;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]>ma)
			{
				ma=a[i];
				k=i;
			}
		}
		//cout<<k<<endl;
		int m;
		cin>>m;
		if(m<5)
		{
			cout<<m<<endl;
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)
		{
			if(i==k)
			{
				for(int j=0;j<=m;++j)dp[i][j]=dp[i-1][j];
				continue;
			}
			for(int j=0;j<=m;++j)
			{
				if(j<a[i])dp[i][j]=dp[i-1][j];
				else dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
			}
		}
		//cout<<ma<<endl;
		int ans=dp[n][m-5]+ma;
		//cout<<dp[n][m]<<endl;
		ans = m-ans;
		cout<<ans<<endl; 
	}
	return 0;
 } 
