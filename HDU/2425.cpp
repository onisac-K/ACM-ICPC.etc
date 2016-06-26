#include<bits/stdc++.h>
using namespace std;

char a[25][25];
int vis[25][25];
int p,s,t;//path sand tree
int n,m;
int mx,my,ex,ey;
int d[4][2]={1,0,-1,0,0,1,0,-1};
int findv(int x,int y)
{
	if(a[x][y]=='T')return t;
	if(a[x][y]=='.')return s;
	if(a[x][y]=='#')return p;
}

int flag;

void bfs()
{
	queue<int >q;
	q.push(mx*25+my);
	while(!q.empty())
	{
		int X=q.front();
		q.pop();
		int x=X/25;
		int y=X%25;
		if(x==ex&&y==ey)flag=1;
		for(int i=0;i<4;++i)
		{
			int tx=x+d[i][0];
			int ty=y+d[i][1];
			//cout<<123<<endl;
			if(tx<0||ty<0||tx>=n||ty>=m||a[tx][ty]=='@')continue;
			if(min(vis[x][y]+findv(tx,ty),vis[tx][ty])==vis[tx][ty]&&vis[tx][ty]!=0)continue;
			else 
			{
				//cout<<123<<endl;
				vis[tx][ty]=vis[x][y]+findv(tx,ty);
				q.push(tx*25+ty);
			}
		}
	}
}

void Debug()
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)cout<<vis[i][j]<<' ';
		cout<<endl;
	}
}

int main()
{
	int f=1;
	while(cin>>n>>m)
	{
		flag=0;
		memset(vis,0,sizeof(vis));
		cin>>p>>s>>t;
		for(int i=0;i<n;++i)scanf("%s",a[i]);
		cin>>mx>>my>>ex>>ey;
		printf("Case %d: ",f++);
		if(mx==ex&&my==ey)
		{
			cout<<0<<endl;
			continue;
		}
		//vis[tx][ty]=findv(tx,ty);
		bfs();
		//Debug();
		
		if(flag)
			cout<<vis[ex][ey]<<endl;
		else cout<<-1<<endl; 
	}
	return 0;
}
