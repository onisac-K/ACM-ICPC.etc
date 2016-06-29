#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int dp[100005];
int sum[100005];
int val[105],num[105];

int main()
{
	int n,m;
	while(cin>>n>>m && (n||m))
	{
		for(int i=1;i<=n;++i)scanf("%d",&val[i]);
		for(int i=1;i<=n;++i)scanf("%d",&num[i]);
		memset(dp,0,sizeof(dp));
		int ans = 0;
		dp[0]=1;
		for(int i=1;i<=n;++i)
		{
			memset(sum,0,sizeof(sum));
			for(int j=val[i];j<=m;++j)
			{
				if(dp[j]==0&&dp[j-val[i]]==1&&sum[j-val[i]]<num[i])
				{
					dp[j]=1;
					sum[j]=sum[j-val[i]]+1;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
