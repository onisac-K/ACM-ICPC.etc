#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1005][1005];
int a[1005],b[1005];


int main()
{
	int n,m;
	//freopen("2","r",stdin);
	while(cin>>n>>m){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=m;++i)scanf("%d",&b[i]);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i] == b[j]){
					ll s = dp[i][j-1] + dp[i-1][j] + 1;
					dp[i][j] = max(dp[i][j],s);
				}
				else dp[i][j] = max(dp[i][j],dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]);
				//dp[i][j] = max(dp[i][j],dp[i][j-1]);
				dp[i][j] = (dp[i][j]+1000000007)%1000000007;
			}		
		}
		while(dp[n][m]<=0)dp[n][m]+=1000000007;
		dp[n][m]%=1000000007;
		cout<<dp[n][m]<<endl;
	}
	return 0;
}
