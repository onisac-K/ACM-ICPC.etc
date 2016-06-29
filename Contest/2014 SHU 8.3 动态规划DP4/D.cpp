#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[100005];
int a[105],num[105];
int sum[100005];

int main()
{
	int n,m;
	while(cin>>n)
	{
		cin>>m;
		for(int i=1;i<=m;++i)scanf("%d%d",&num[i],&a[i]);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;++i)
		{
			memset(sum,0,sizeof(sum));
			for(int j=a[i];j<=n;++j)
			{		
				if(sum[j-a[i]]<num[i]&&dp[j]<dp[j-a[i]]+a[i])
				{
					dp[j]=dp[j-a[i]]+a[i];
					sum[j]=sum[j-a[i]]+1;
				}	
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
 
