#include<bits/stdc++.h>
using namespace std;
int k[2005];
int f[2005];
int dp[2005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int l,n;
		cin>>l>>n;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;++i)scanf("%d",&k[i]);
		for(int i=0;i<n;++i)scanf("%d",&f[i]);
		int min=999999;
		int minl=0;
		for(int i=0;i<=l;++i)
		{
			for(int j=0;j<n;++j)
			{
				int s=fabs(k[j]-i);
				dp[i]+=max(0,f[j]-s);
			}
			if(dp[i]<min)
			{
				min=dp[i];
				minl=i;
			}
		}
		cout<<minl<<' '<<min<<endl;
	}
	return 0;
}
  
