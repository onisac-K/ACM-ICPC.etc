#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f 
ll a1[205][205],a2[205][205];
ll dp[1005][205];
int t[1005];

void init(int n){
	memset(dp,INF,sizeof(dp));
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			a1[i][j] = (i==j? 0 : INF);
			a2[i][j] = a1[i][j];
		}
	}
}

int main()
{
	int n,m;
	while(cin>>n>>m && (n||m)){
		init(n);
		int u,v,d;
		char f[2];
		for(int i=1;i<=m;++i){
			scanf("%d%d%d%s",&u,&v,&d,f);
			if(f[0]=='L'){
				a1[u][v] = min(a1[u][v],1LL*d);
				a1[v][u] = min(a1[v][u],1LL*d);
			}
			else {
				a2[u][v] = min(a2[u][v],1LL*d);
				a2[v][u] = min(a2[v][u],1LL*d);
			}
		}
		for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                a1[i][j] = min(a1[i][j],a1[i][k] + a1[k][j]);
            }}}
		for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                a2[i][j] = min(a2[i][j],a2[i][k] + a2[k][j]);
            }}}
            
        int r;
        cin>>r;
        for(int i=1;i<=r;++i)scanf("%d",&t[i]);
        dp[1][t[1]] = 0;
        for(int i=1;i<=r;++i){
        	for(int j=1;j<=n;++j){
        		dp[i][j] = min(dp[i][j],dp[i-1][j]+a1[t[i-1]][t[i]]);
        		for(int k=1;k<=n;++k){
        			dp[i][j] = min(dp[i][j],dp[i-1][k]+a1[t[i-1]][k]+a2[k][j]+a1[j][t[i]]);
				}
			}
		}
		ll ans = INF;
		for(int i=1;i<=n;++i)ans = min(ans,dp[r][i]);
		cout<<ans<<endl;
	}
	return 0;
}
