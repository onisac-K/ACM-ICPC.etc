#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int dp[4][1005][1005];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)scanf("%s",a[i]);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(a[i-1][j-1]=='.')
				{
					dp[0][i][j]=dp[0][i-1][j]+1;
					dp[1][i][j]=dp[1][i][j-1]+1;
				}
				else
				{
					dp[0][i][j]=0;
					dp[1][i][j]=0;
				}
			}
		}
		for(int i=n;i>=1;--i)
		{
			for(int j=m;j>=1;--j)
			{
				if(a[i-1][j-1]=='.')
				{
					dp[2][i][j]=dp[2][i+1][j]+1;
					dp[3][i][j]=dp[3][i][j+1]+1;
				}
				else
				{
					dp[2][i][j]=0;
					dp[3][i][j]=0;
				}
			}
		}
		int ans=0;
		for(int i=n;i>=1;--i)
		{
			for(int j=m;j>=1;--j)
			{
				int f=0;			
				for(int k=0;k<4;++k)
				{
					f+=dp[k][i][j];
				}				
				if(f>ans)ans=f;
			}
		}
		/*for(int i=0;i<4;++i)
		{
			for(int j=1;j<=n;++j)
			{
				for(int k=1;k<=m;++k)cout<<dp[i][j][k]<<' ';
				cout<<endl;
			}
			cout<<endl;
		}*/
		cout<<ans-4<<endl;
	}
}
