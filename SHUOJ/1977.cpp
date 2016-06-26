#include <bits/stdc++.h>
using namespace std;

int dp[100005][10];
char a[100005];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",a);
		int len=strlen(a);
		for(int i=0;i<len+5;++i)
		{
			for(int j=0;j<10;++j)dp[i][j]=9999999;
		}
		for(int i=0;i<10;++i)dp[0][i]=0;
		for(int i=0;i<len;++i)
		{
			int f=(a[i]-'0');
			for(int j=0;j<10;++j)
			{
				dp[i+2][j]=min(dp[i+2][j],dp[i][j]+1);
				if(j!=0)dp[i+1][0]=min(dp[i+1][0],dp[i][j]+1);
				if(f!=j)dp[i+1][f]=min(dp[i+1][f],dp[i][j]);
			}
		}
		int ans=INT_MAX;
		for(int i=0;i<10;++i)
		{
			//cout<<ans<<endl;
			ans=min(ans,dp[len][i]); 
		}
		cout<<ans<<endl;
	}
	return 0;
} 
