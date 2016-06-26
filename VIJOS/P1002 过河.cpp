#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[15];
int M[105];

int main()
{
	int L,s,t,m;
	int ans=INT_MAX;
	cin>>L>>s>>t>>m;
	for(int i=1;i<=m;++i)scanf("%d",&M[i]);
	if(s==t)
	{
		int ans1=0;
		for(int i=1;i<=m;++i)
		{
			if(M[i]%s==0)ans1++;
		}
		cout<<ans1<<endl;
	}
	else
	{
		sort(M+1,M+1+m);
		dp[0]=0;
		int last=101,count=0;
		for(int i=1;i<t;++i)dp[i]=101;
		int i=s,p=1;
		while(i<=(t+L))
		{
			if(i==M[p])dp[i%t]++;
			for(int j=t;j>=s;--j)
			{
				dp[i%t]=min(dp[i%t],dp[(i-j+t)%t]+(i==M[p]));
			}
			if(i>=M[p]&&p<=m)p++;
			if(dp[i%t]==last)count++;
			else 
			{
				last=dp[i%t];
				count=1;
			}
			i++;
			if(count>t&&i<L)
			{
				if(p<=m)i=M[p];
				else i=L;
				count=0;
			}
		}
		ans=INT_MAX;
		for(int k=L;k<=L+t;++k)ans=min(ans,dp[k%t]);
		cout<<ans<<endl;
	}
	
	return 0;
}
