#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[205][105];// n,s
int a[105],b[105];

int main()
{
	int n,m,k,s;
	while(cin>>n>>m>>k>>s)
	{
		memset(dp,0x3f3f3f3f,sizeof(dp));
		for(int i=1;i<=k;++i)scanf("%d%d",&a[i],&b[i]);
		dp[0][0]=0;	
		int mini = 99999999;
		for(int q=1;q<=k;++q)
		{
			int j = a[q];
			while(1)
			{
				for(int i=1;i<=s;++i)
				{
					dp[j][i]=min(dp[j][i],dp[j-a[q]][i-1]+b[q]);
				}
				j++;
				if(j>=n+a[q])break;
			}	
		}
		for(int i=n;i<205;++i)
		{
			for(int j=1;j<=s;++j)
				mini = min(mini,dp[i][j]);
		}
		mini = m-mini;
		cout<<((mini>=0)? mini:-1)<<endl;
	}
	return 0;
}

