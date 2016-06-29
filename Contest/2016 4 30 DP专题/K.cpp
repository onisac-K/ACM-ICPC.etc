#include<bits/stdc++.h>
using namespace std;

int a[105];
int sum[105];
int dp[105][105];  

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,w;
		memset(sum,0,sizeof(sum));
		memset(dp,0x3f3f3f,sizeof(dp));
		cin>>n>>w;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
		//for(int i=1;i<=n;++i)cout<<a[i]<<endl;
		for(int i=1;i<=n;++i)
			dp[i][1]=sum[i]*i;
		for(int i=1;i<=n;++i)
		{
			for(int j=2;j<=w;++j)
			{
				if(j>i)break;
				//dp[i][j]=min(dp[i][j],dp[i-1][j]+i*a[i]);
				//dp[i][j]=min(dp[i][j],dp[i-1][j-1]+i*a[i]);
				for(int k=1;k<=i;++k)
				{
					dp[i][j]=min(dp[i][j],dp[k-1][j-1]+(sum[i]-sum[k-1])*i);
					//dp[i][j]=min(dp[i][j],dp[k-1][j]+(sum[i]-sum[k-1])*i);
				}
			}
		}
	/*	for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=w;++j)cout<<dp[i][j]<<' ';
			cout<<endl;
		}*/
		double ans = dp[n][w]*1.0/sum[n];
		printf("%.4f\n",ans);
	}
}

/*
2
5 2
30 5 10 30 25
5 5
30 5 10 30 25
*/
