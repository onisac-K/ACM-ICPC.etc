#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
ll dp[12][2100];
int n,m,cnt;
int path[14000][2];

void getpath(int l,int now,int end){
	if(l > n)return ;
	if(l == n){
		path[cnt][0] = now;
		path[cnt++][1] = end;
		return;
	}
	getpath(l+2,(now<<2)|3,(end<<2)|3);
	getpath(l+1,(now<<1)|1,(end)<<1);
	getpath(l+1,(now<<1),(end<<1)|1);	
} 

int main()
{
	while(cin>>n>>m && (n||m)){
		int x = min(n,m);
		int y = n+m-x;
		n = x;m = y;
		cnt = 0;
		memset(dp,0,sizeof(dp));
		memset(path,0,sizeof path);
		getpath(0,0,0);
		dp[0][(1<<n)-1] = 1;
		for(int i=1;i<=m;++i){
			for(int j=0;j<cnt;++j){
				dp[i][path[j][1]] += dp[i-1][path[j][0]];
			}
		}
		cout<<dp[m][(1<<n)-1]<<endl;
	}
	return 0;
 } 
