#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000];

int main()
{
	int n;
	dp[0]=0;
	dp[1]=3;
	dp[2]=6;
	dp[3]=6;
	for(int i=4;i<=60;++i)dp[i]=dp[i-1]+2*dp[i-2];
	while(cin>>n)cout<<dp[n]<<endl;
	return 0;
} 
