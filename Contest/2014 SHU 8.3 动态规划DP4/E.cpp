#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

double dp[2][1000005];

int main()
{
	int c,n,m;
	double ans=0;
	while(cin>>c && c)
	{
		cin>>n>>m;
		memset(dp,0,sizeof(dp));
		dp[1][1]=1.0;
		dp[0][0]=1.0;
		if(n>1000)n=n%2+1000;
		for(int i=2;i<=n;++i)
		{
			for(int j=0;j<=i&&j<=c;++j)
			{
				if(j==0)dp[i%2][j]=dp[(i-1)%2][1]*1.0/c;
				else if(j==c)dp[i%2][j]=dp[(i-1)%2][c-1]*1.0/c;
				else dp[i%2][j]=dp[(i-1)%2][j-1]*(c-j+1)*1.0/c+dp[(i-1)%2][j+1]*(j+1)*1.0/c;
				//cout<<dp[i%2][m]<<endl;
			}
		}
		printf("%.3f\n",dp[n%2][m]);
	}
	return 0;
}
