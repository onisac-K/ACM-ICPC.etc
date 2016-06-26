#include<bits/stdc++.h>
using namespace std;
int a[505];
int dp[505][505];
int main()
{
	int n,m;
	int ffff=1;
	while(cin>>n>>m)
	{
		
		
		int sum;
	    int s[505];
		for(int i=0;i<505;++i)for(int j=0;j<505;++j)dp[i][j]=99999999;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			sum+=a[i];
			s[i]=sum;
			dp[1][i]=sum;
		}
		
		for(int i=2;i<=m;++i)
		{
			dp[i][0]=0;
			for(int j=1;j<=n;++j)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]);
				for(int k=1;k<=j;++k)
				{
					cout<<dp[i-1][k]<<' '<<dp[i-1][j]<<endl;
					if(k<j)dp[i][j]=min(dp[i][j],max(dp[i-1][k],s[j]-s[k]));
					else dp[i][j]=min(dp[i][j],dp[i-1][j]);
					cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
				}
			}
		}
		printf("Case %d: ",ffff++);
		cout<<dp[m][n]<<endl;
	}
}
