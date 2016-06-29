#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

char a[(1+55)*55/2];
ll dp[55][55];

ll gcd(ll a, ll b)
{
	return ((b%a==0) ? a:gcd(b,a%b));
}

int main()
{
	int n,m;
	cin>>n>>m;
	char s[5];
	int step=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
		{
			scanf("%s",s);
			a[step++]=s[0];
		}
	}
	dp[1][1]=((ll)1)<<n;
	for(int i=1;i<=n;++i)
	{
		int k = (1+i-1)*(i-1)/2;
		for(int j=1;j<=i;++j)
		{
			if(a[k+j]=='*')
			{
				dp[i+1][j]+=dp[i][j]>>1;
				dp[i+1][j+1]+=dp[i][j]>>1;
			} 
			else 
			{
				dp[i+2][j+1]+=dp[i][j];
			}	
		}
	}
	/*ll g=0;
	for(int i=1;i<=n+1;++i)g+=dp[n+1][i];*/
	ll mm = gcd(dp[n+1][m+1],dp[1][1]);
	if(dp[n+1][m+1]==0)
	{
		cout<<"0/1"<<endl;
	}
	else 
	cout<<dp[n+1][m+1]/mm<<'/'<<dp[1][1]/mm<<endl;
	return 0;
}
