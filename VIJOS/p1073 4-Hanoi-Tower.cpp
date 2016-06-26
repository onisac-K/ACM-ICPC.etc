#include<bits/stdc++.h>
using namespace std;

int dp[50005];

int main()
{
	dp[0]=0;
	int f=1;
	int flag=0;
	int m=1;
	
	for(int i=1;i<=50000;++i)
	{
		dp[i]=dp[i-1]+f;
		dp[i]%=10000;
		flag++;
		if(flag>=m)
		{
			m++;		
			flag=0;
			f*=2;
			f%=10000;
		}
	}
	//for(int i=0;i<=100;++i)cout<<dp[i]<<endl;
	int n;
	while(cin>>n)cout<<dp[n]<<endl;
	return 0;
} 
