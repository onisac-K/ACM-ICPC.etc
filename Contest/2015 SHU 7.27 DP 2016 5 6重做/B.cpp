#include<bits/stdc++.h>
using namespace std;

//int a[105][105];
int dp[105][105];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<=i;++j)
			{
				scanf("%d",&dp[i][j]);
			}
		}
		for(int i=n-2;i>=0;--i)
		{
			for(int j=0;j<=i;++j)
			{
				int ans=max(dp[i+1][j],dp[i+1][j+1]);
				dp[i][j]+=ans;
			}
		}
		cout<<dp[0][0]<<endl;
	}
	
}
