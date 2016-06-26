#include<bits/stdc++.h>
using namespace std;

int dp[105][2005];
int a[105];
int sum[105];

int main()
{
	int n;
	cin>>n;
	memset(dp,-0x3f3f3f,sizeof(dp));
	//cout<<dp[0][0]<<endl;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	dp[1][0]=0;
	dp[1][a[1]]=0;
	for(int i=2;i<=n;++i)
	{
		for(int j=0;j<=sum[i];++j)
		{
			if(j<=sum[i-1])dp[i][j]=max(dp[i][j],dp[i-1][j]);
			if(j-a[i]<=sum[i-1]&&j-a[i]>=0)dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]);
			if(j+a[i]>=0&&j+a[i]<=sum[i-1]&&dp[i-1][j+a[i]]+a[i]<=sum[i])dp[i][j]=max(dp[i][j],dp[i-1][j+a[i]]+a[i]);
			if(a[i]-j>=0&&a[i]-j<=sum[i-1]&&dp[i-1][a[i]-j]+a[i]-j<=sum[i])dp[i][j]=max(dp[i][j],dp[i-1][a[i]-j]+a[i]-j);
		}
	}
	
	int ans=0;
	/*for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=sum[i];++j)
		{
			if(dp[i][j]>=0)cout<<i<<' '<<j<<' '<<dp[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int i=1;i<=n;++i)if(dp[i][0]>=0)ans=max(ans,dp[i][0]);
	if(ans==0)cout<<"Impossible"<<endl;
	else cout<<ans<<endl;
	return 0;
}

