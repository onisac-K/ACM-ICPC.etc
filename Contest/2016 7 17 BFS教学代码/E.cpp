#include<queue>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n,m,l;
char G[35][35][35];
int vis[35][35][35];
int dir[6][3]={1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};

void bfs(int i,int j,int k)
{
	queue<int>q;
	q.push(i*1600+j*40+k);
	vis[i][j][k]=1;
	while(!q.empty()){
		int T = q.front();
		q.pop();
		int x = T/1600;
		int y = (T%1600)/40;
		int z = T%40;
		for(int i=0;i<6;++i){
			int tx = x + dir[i][0];
			int ty = y + dir[i][1];
			int tz = z + dir[i][2];
			if(tx<0||tx>=l||ty<0||ty>=n||tz<0||tz>=m)continue;
			if(vis[tx][ty][tz]!=0 || G[tx][ty][tz]=='#')continue;
			vis[tx][ty][tz] = vis[x][y][z]+1;
			q.push(tx*1600+ty*40+tz);
		}
	}
}

int main()
{
	while(cin>>l>>n>>m && (n||m||l)){
		memset(vis,0,sizeof(vis));
		for(int i=0;i<l;++i)
			for(int j=0;j<n;++j)
				scanf("%s",G[i][j]);
		int L,N,M;
		for(int i=0;i<l;++i)
			for(int j=0;j<n;++j)
				for(int k=0;k<m;++k){
					
					if(G[i][j][k] == 'S'){
						bfs(i,j,k);
					}
					if(G[i][j][k] == 'E'){
						L = i;
						N = j;
						M = k; 
					}
				}
		if(vis[L][N][M]==0)cout<<"Trapped!"<<endl;
		else printf("Escaped in %d minute(s).\n",vis[L][N][M]-1);	
	}
	return 0;
}
