#include<bits/stdc++.h>
using namespace std;

int dp[50];

int a[50];

int main()
{
	int n;
	while(cin>>n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		sort(a,a+n);
		int ans=0;
	
		int i=n-1;
		
		int d=a[1]+a[0]+a[1];
		dp[1]=a[0];
		dp[2]=a[1];
		dp[3]=a[2]+a[1]+a[0];
		
		for(int i=n-1;i>2;++i)
		{						
			dp[i]=min(dp[i-1]+a[i-1]+a[0],a[i-1]+dp[i-2]+d);
		}			
	}
}
