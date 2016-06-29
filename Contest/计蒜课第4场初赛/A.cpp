#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100004];
ll dp[100004][2];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	ll maxn=0;
	for(int i=1;i<=n;++i)
	{
		dp[i][1]=a[i];
		for(int j=1;j<=i-2;++j)
			dp[i][1]=max(dp[i][1],max(dp[j][0],dp[j][1])+a[i]);
		for(int j=1;j<=i-1;++j)
			dp[i][0]=max(dp[j][1],dp[j][0]);
		maxn = max(maxn,max(dp[i][0],dp[i][1]));
	}
	cout<<maxn<<endl;
	return 0;
} 
