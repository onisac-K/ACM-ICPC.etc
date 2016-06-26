#include<bits/stdc++.h>
#include<queue>
using namespace std;

char a[1005][1005];
int vis[1005][1005],X;
int d[4][2]={1,0,-1,0,0,1,0,-1};
int n,m,tx,ty;
int Y=1;

int bfs(int x ,int y)
{	
	queue<int> q;
	q.push(x*1005+y);
	//vis[x][y]=1;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		int x=t/1005;
		int y=t%1005;
		//cout<<x<<' '<<y<<' '<<a[x][y]<<endl;
		if(a[x][y]<='9'&&a[x][y]>='1'&&(a[x][y]-'0')<=Y)
		{
			//cout<<a[x][y]-'0'<<endl;
			Y++;
			a[x][y]='.';
			//cout<<x<<' '<<y<<endl;
			tx=x;
			ty=y;
			return 1;
		}
		for(int i=0;i<4;++i)
		{
			int kx=x+d[i][0];
			int ky=y+d[i][1];
			if(kx<0||kx>=n||ky<0||ky>=m||a[kx][ky]=='X'||vis[kx][ky]!=0)continue;
			vis[kx][ky]=vis[x][y]+1;
			q.push(kx*1005+ky);
		}
	}
	return -1;
}

int main()
{
	cin>>n>>m>>X;
	for(int i=0;i<n;++i)scanf("%s",a[i]);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(a[i][j]=='S')
			{
				tx=i;ty=j;
			}
		}
	}
	//cout<<tx<<' '<<ty<<endl;
	int ans=0;
	while(bfs(tx,ty)==1)
	{
		ans+=vis[tx][ty];
		memset(vis,0,sizeof(vis));
	}
	cout<<ans<<endl;
	return 0;
} 
