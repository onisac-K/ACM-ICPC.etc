#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

char a[35][35][35];
int vis[35][35][35];
int L,n,m;
int tl,tx,ty,el,ex,ey;
int d[4][2]={1,0,0,1,-1,0,0,-1};

void Debug()
{
	for(int i=0;i<L;++i)
	{
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<m;++k)
			{
				cout<<vis[i][j][k]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
				
	}
			
}

void bfs()
{
	queue<int>q;
	q.push(tl*900+tx*30+ty);
//	vis[tl][tx][ty]=1;
	while(!q.empty())
	{
		//Debug();
		int T=q.front();
		q.pop();
		int l=T/900;
		int x=(T%900)/30;
		int y=((T%900)%30);
		if(l==el&&x==ex&&y==ey)
		{
			return ;
		}
		for(int i=0;i<4;++i)
		{
			int xx=x+d[i][0];
			int xy=y+d[i][1];
			if(xx<0||xx>=n||xy<0||xy>=m)continue;
			if(vis[l][xx][xy]!=0||a[l][xx][xy]=='#')continue;
			else {
				q.push(l*900+xx*30+xy);
				vis[l][xx][xy]=vis[l][x][y]+1;
			}
		}
		int up=l+1;
		if(up<L&&vis[up][x][y]==0&&a[up][x][y]!='#')
		{
			vis[up][x][y]=vis[l][x][y]+1;
			q.push(up*900+x*30+y);
		}
		int dn=l-1;
		if(dn>=0&&vis[dn][x][y]==0&&a[dn][x][y]!='#')
		{
			vis[dn][x][y]=vis[l][x][y]+1;
			q.push(dn*900+x*30+y);
		}
	}
}

int main()
{
	while(cin>>L>>n>>m&&(L||n||m))
	{
		memset(vis,0,sizeof(vis));
		for(int i=0;i<L;++i)
			for(int j=0;j<n;++j)scanf("%s",a[i][j]);
		for(int i=0;i<L;++i)
			for(int j=0;j<n;++j)
				for(int k=0;k<m;++k)
				{
					if(a[i][j][k]=='S')
					{
						tl=i;tx=j;ty=k;
					}
					if(a[i][j][k]=='E')
					{
						el=i;ex=j;ey=k;
					}
				}
		//cout<<el<<' '<<ex<<' '<<ey<<endl;
		bfs();
		if(vis[el][ex][ey]==0)
		{
			printf("Trapped!\n");
		}
		else printf("Escaped in %d minute(s).\n",vis[el][ex][ey]);
	}
}
