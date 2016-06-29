#include<bits/stdc++.h>
using namespace std;

int dp[55*50*100];
int a[55],num[55];

int main()
{
	int n;
	while(cin>>n && n>0)
	{
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(num,0,sizeof(num));
		int m=0;	
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&a[i],&num[i]);
			m+=a[i]*num[i];
		}
		dp[0]=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=m;j>=0;--j)
			{
				for(int k=0;k<=num[i];++k)
				{
					if(j>=k*a[i])dp[j]=max(dp[j],dp[j-k*a[i]]);
				}
			}
		}
		int ma = 0;
		for(int i=0;i<=m/2;++i)
		{
			if(dp[i])ma=i;
		}
		cout<<m-ma<<' '<<ma<<endl;
	}
	return 0;
} 
