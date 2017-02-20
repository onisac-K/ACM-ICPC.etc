#include<bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
char G[5][5];
int dp[1<<16][25][25];
int p[5][5];
int n,m;
int cnt = 0;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int vis[1<<16][25][25];


int dfs(int v,int s1,int s2){
	
	if(v == (1<<cnt)-1) return 0;
	if(dp[v][s1][s2] != INF)return dp[v][s1][s2];
	int ans = INF;
	for(int i=0;i<4;++i){
		int tx1 = s1/4+dir[i][0];
		int ty1 = s1%4+dir[i][1];
		if(G[tx1][ty1]=='X' || tx1<0||ty1<0||tx1>=n||ty1>=m)continue;
		for(int j=0;j<4;++j){
			int tx2 = s2/4+dir[j][0];
			int ty2 = s2%4+dir[j][1];
			if(G[tx2][ty2]=='X' || tx2<0||ty2<0||tx2>=n||ty2>=m)continue;
			if(vis[v|(1<<p[tx1][ty1])|(1<<p[tx2][ty2])][tx1*4+ty1][tx2*4+ty2] == 1)continue;
			vis[v|(1<<p[tx1][ty1])|(1<<p[tx2][ty2])][tx1*4+ty1][tx2*4+ty2] = 1;
			ans = min(ans,1+dfs(v|(1<<p[tx1][ty1])|(1<<p[tx2][ty2]),tx1*4+ty1,tx2*4+ty2));
			vis[v|(1<<p[tx1][ty1])|(1<<p[tx2][ty2])][tx1*4+ty1][tx2*4+ty2] = 0;
		}
	} 
	return dp[v][s1][s2]=ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(dp,INF,sizeof dp);
		memset(vis,0,sizeof vis);
		for(int i=0;i<n;++i)scanf("%s",G[i]);
		int tx,ty;
		cnt = 0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(G[i][j] == 'S'){
					tx = i;
					ty = j;
				}
				if(G[i][j] == 'S'||G[i][j] == 'O')
					p[i][j] = cnt++;	
			}
		}
		vis[1<<(p[tx][ty])][tx*4+ty][tx*4+ty]=1;
		cout<<dfs(1<<(p[tx][ty]),tx*4+ty,tx*4+ty)<<endl;
	}
	return 0;
}
