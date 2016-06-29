#include<bits/stdc++.h>
using namespace std;

int dp[2105][2105];
int f[2105][2105];
char a[2105],b[2105];

int main()
{
	int k;
	while(~scanf("%s %s",a,b))
	{
		scanf("%d",&k);
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		int n = strlen(a);
		int m = strlen(b);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(a[i-1]==b[j-1])f[i][j]=f[i-1][j-1]+1;
			}
		}
		//cout<<f[2][2]<<endl;
		for(int i=k;i<=n;++i)
		{
			for(int j=k;j<=m;++j)
			{
				if(a[i-1]==b[j-1]&&f[i][j]>=k)
				{
					dp[i][j]=dp[i-f[i][j]][j-f[i][j]]+f[i][j];
					dp[i][j]=max(dp[i][j],dp[i-k][j-k]+k);
				}
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				
			}
		}
		cout<<dp[n][m]<<endl;
	}
	
	return 0;
} 
