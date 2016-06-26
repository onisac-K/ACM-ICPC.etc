#include<bits/stdc++.h>
using namespace std;

int dp[8][10]={0};

void init()
{
	dp[0][0]=1;
	for(int i=1;i<=7;++i)
	{
		for(int j=0;j<=9;++j)
		{
			if(j==4)continue;
			for(int k=0;k<=9;++k)
			{
				if(k==4||(j==6&&k==2))continue;
				dp[i][j]+=dp[i-1][k];
			}
		}
	}
}

int num[10];

int solve(int n)
{
	int t=0;
	memset(num,0,sizeof(num));
	while(n>0)
	{
		num[++t]=n%10;
		n/=10;
	}
	int ans=0;
	//cout<<num[t]<<endl;
	//cout<<t<<endl;
	for(int i=t;i>0;--i)
	{
		for(int j=0;j<num[i];++j)
		{
			if(j==4)continue;
			if(num[i+1]==6&&j==2)continue;
			ans+=dp[i][j];
		}
		if (num[i]==4||(num[i]==2&&num[i + 1]==6))
			break;
	}
	return ans;
}

int main()
{
	int a,b;
	init();
	//for(int i=0;i<8;++i)for(int j=0;j<10;++j)cout<<dp[i][j]<<endl;
	while(cin>>a>>b,a||b)
	{
		cout<<solve(b+1)-solve(a)<<endl;
	}
}
