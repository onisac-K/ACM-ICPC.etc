#include<bits/stdc++.h>
using namespace std;

int dp[50*55*100];
int a[55],num[55];

int main()
{
	int n;
	while(cin>>n && n>0)
	{
		memset(dp,0,sizeof(dp));
		int m = 0;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i]>>num[i];
			m+=a[i]*num[i];
		}
		
		for(int i=1;i<=n;++i)
		{
			for(int j=m/2;j>=a[i];--j)
			{
				for(int k=0;k<=num[i];++k)
				{
					if(j>=k*a[i])
					{
						dp[j]=max(dp[j],dp[j-k*a[i]]+k*a[i]);
					}
				}
			}
		}
		cout<<m-dp[m/2]<<' '<<dp[m/2]<<endl;
	}
	return 0;
}
