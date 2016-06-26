#include<bits/stdc++.h>
using namespace std;

char a[2005][80];
int dp[2005];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		scanf("%s",a[i]);
	}
	for(int i=0;i<n;++i)dp[i]=1;
	int ans=1;
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(strstr(a[i],a[j])==a[i])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
			ans=max(ans,dp[i]);
		}
	}
	cout<<ans<<endl;
	
	//for(int i=0;i<n;++i)cout<<dp[i]<<endl;	
	return 0;
}
