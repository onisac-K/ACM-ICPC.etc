#include<bits/stdc++.h>
using namespace std;

int dp[1000005][10];
int main()
{
	for(int i=1;i<=1000000;++i)
	{
		int s=i;
		for(int j=0;j<=9;++j)dp[i][j]=dp[i-1][j];
		while(s>0)
		{
			int k=s%10;
			dp[i][k]+=1;
			s/=10;
		}
	}
	int n,m;
	/*for(int i=0;i<=11;++i)
	{
		for(int j=0;j<=9;++j)cout<<dp[i][j]<<' ';
		cout<<endl;
	}*/
	while(cin>>n>>m)
	cout<<dp[n][m]<<endl;
}
