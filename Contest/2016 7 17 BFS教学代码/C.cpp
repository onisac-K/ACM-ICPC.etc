#include<bits/stdc++.h>
using namespace std;

char G[205][205];
int vis[205][205][2];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int n,m;

void bfs(int i,int j,int f)
{
	queue<int>q;
	q.push(i*205+j);
	vis[i][j][f]=1;
	while(!q.empty()){
		int s = q.front();
		q.pop();
		int x = s/205;
		int y = s%205;
		for(int i=0;i<4;++i){
			int tx = x + dir[i][0];
			int ty = y + dir[i][1];
			if(tx<0 || ty<0 || tx>=n || ty>=m)continue;
			if(vis[tx][ty][f]!=0 || G[tx][ty]=='#')continue;
			vis[tx][ty][f] = vis[x][y][f]+1;
			q.push(tx*205+ty);
		}
	}
}

int main()
{
	while(cin>>n>>m){
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i)scanf("%s",G[i]);	
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(G[i][j] == 'Y')bfs(i,j,1);
				if(G[i][j] == 'M')bfs(i,j,0);
			}
		}
		int ans = 0x3f3f3f3f;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(G[i][j] == '@'){
					int S = vis[i][j][0]+vis[i][j][1];
					if(vis[i][j][0] == 0 || vis[i][j][1] == 0)continue;
					ans = min(ans,S);
				}
			}
		}
		cout<<(ans-2)*11<<endl;
	}
	return 0;
 } 
