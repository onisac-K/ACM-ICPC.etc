#include<bits/stdc++.h>
using namespace std;

int dp[1005];
char a[1005];

bool judge(int i,int j)
{
	for(int k=0;k<=(j-i)/2;++k)
	{
		if(a[i+k]!=a[j-k])return false;
	}
	return true;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",a);
		int L = strlen(a);
		memset(dp,0x3f3f3f3f,sizeof(dp));
		dp[0]=0;
		for(int i=1;i<=L;++i)
		{
			for(int j=1;j<=L;++j)
			{
				if(judge(i-1,j-1))dp[j]=min(dp[j],dp[i-1]+1);
			}
			//for(int i=0;i<=L;++i)cout<<dp[i]<<' ';
			//cout<<endl;
		}
		cout<<dp[L]<<endl;
	}
	return 0;
}

/*
3
racecar
fastcar
aaadbccb
*/
 
