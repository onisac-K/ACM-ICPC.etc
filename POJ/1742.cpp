#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[100005];
int cnt[100005];

void debug(int n)
{
	for(int i=1;i<=n;++i)cout<<dp[i]<<' ';cout<<endl;
}

int main()
{
	int n,m;
	while(cin>>n>>m && (n||m))
	{
		int a[105],c[105];
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)scanf("%d",&c[i]);
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=n;++i){
			memset(cnt,0,sizeof(cnt));
			for(int j=a[i];j<=m;++j){
			//	cout<<j<<' '<<dp[j]<<' '<<dp[j-a[i]]<<' '<<cnt[j-a[i]]<<endl;
			
				if(dp[j]==0 && dp[j-a[i]] && cnt[j-a[i]]<c[i]){
					dp[j]=1;
					cnt[j]=cnt[j-a[i]]+1;
				}
			
			}
			//debug(m);
		}
		int ans = 0;
		for(int i=1;i<=m;++i)if(dp[i])ans++;

		cout<<ans<<endl;
	}
	return 0;
}
