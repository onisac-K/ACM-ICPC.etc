#include<bits/stdc++.h>
using namespace std;

int dp[105][105];
int a[105];
int sum[105];

int main()
{
	int n;
	while(cin>>n && n)
	{
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=1;i<=n;++i)dp[i][i]=a[i];
		for(int l=2;l<=n;++l)
		{
			for(int i=1,j=l;j<=n;i++,j++)
			{
				int ans=-100000000;
				for(int k=i;k<=j;++k)
				{
					int q=min(dp[i][k],dp[k+1][j]);
					q=sum[j]-sum[i-1]-q;
					ans=max(ans,q);
				}
				ans=max(ans,sum[j]-sum[i-1]);
				dp[i][j]=ans;
			}
		}
		printf("%d\n",2*dp[1][n]-sum[n]);
	}
	return 0;
}

/*
4
4 -10 -20 7
4 
1 2 3 4
0
*/
