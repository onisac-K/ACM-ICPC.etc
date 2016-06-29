#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[505],w[505];
ll dp[10005];

int main()
{
	int t;
	cin>>t;
	int e,f;
	while(t--)
	{
		scanf("%d%d",&e,&f);
		int m = f-e;
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&w[i]);
		memset(dp,0x3f3f3f3f,sizeof(dp));
		ll xx=dp[0];
		dp[0]=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=w[i];j<=m;++j)
				dp[j]=min(dp[j],dp[j-w[i]]+a[i]);
		}
		if(dp[m]==xx)printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
	}
	return 0;
} 
