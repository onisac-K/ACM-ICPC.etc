#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int T[305][305],vis[305][305];
int d[4][2]={1,0,-1,0,0,1,0,-1};
const int INF=99999999;

bool Inline(int x,int y)
{
	if(x>=0&&y>=0)return true;
	return false;
}

int bfs()
{
	queue<int>q;
	q.push(0);
	if(T[0][0]==0)return -1;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		int x=t/305;
		int y=t%305;
		//if(vis[x][y]>=T[x][y])return -1;
		if(T[x][y]==INF)
		{
			return vis[x][y];
		}
		for(int i=0;i<4;++i)
		{
			int tx=x+d[i][0];
			int ty=y+d[i][1];
			if(Inline(tx,ty)&&vis[x][y]+1<T[tx][ty]&&vis[tx][ty]==0)
			{
				vis[tx][ty]=vis[x][y]+1;
				q.push(tx*305+ty);
			}
		}
	}
	return -1;
}

int main()
{
	int n;
	int a,b,c;
	cin>>n;
	for(int i=0;i<305;++i)
		for(int j=0;j<305;++j)T[i][j]=INF; 
	for(int i=0;i<n;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		T[a][b]=min(T[a][b],c);
		for(int j=0;j<4;++j)
		{
			int ta=a+d[j][0];
			int tb=b+d[j][1];
			if(Inline(ta,tb))T[ta][tb]=min(T[ta][tb],c);
		}
	}
	//Debug
	/*for(int i=0;i<5;++i)
	{
		for(int j=0;j<5;++j)cout<<T[i][j]<<' ';
		cout<<endl;
	}
	bfs();
	for(int i=0;i<5;++i)
	{
		for(int j=0;j<5;++j)cout<<vis[i][j]<<' ';
		cout<<endl;
	}*/
	cout<<bfs()<<endl;
}
