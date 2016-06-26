#include<bits/stdc++.h>
using namespace std;

int dp[10005][5005];
int a[5005],b[5005];

int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)b[i]=a[n+1-i];
	memset(dp,0x3f3f3f3f,sizeof(dp));
	for(int i=0;i<=n;++i)dp[0][i]=0;
	dp[1][1]=0;
	dp[1][2]=0;
	for(int i=1;i<=m;++i)
	{
		for(int j=3*i;j<=n;++j)
		{
			if(j==3*i)dp[i][j]=min(dp[i][j],dp[i-1][j-2]+(b[j]-b[j-1])*(b[j]-b[j-1]));
			else 
			{
				dp[i][j]=min(dp[i][j-1],min(dp[i][j],dp[i-1][j-2]+(b[j]-b[j-1])*(b[j]-b[j-1])));
			}
		}
	}
	cout<<dp[m][n]<<endl;
}
