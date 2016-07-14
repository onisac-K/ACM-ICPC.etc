#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define ll long long

ll dp[1000005];

int main(){
	int n;
	cin>>n;
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(i&1)
			dp[i]=dp[i-1];
		else dp[i]=dp[i-1]+dp[i/2];
		dp[i]%=1000000000;
	}
	cout<<dp[n]<<endl;
	return 0;
}
