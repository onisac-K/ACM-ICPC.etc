#include<bits/stdc++.h>
using namespace std;

char a[10][10]; 
int n;
int vis[10][10];

bool in(int x,int y)
{
	if(x<0||x>=n||y<0||y>=n)return false;
	return true;
}

bool check(int x,int y)
{
	for(int i=0;i<n;++i)
	{
		if(!in(x+i,y))break;
		if(a[x+i][y]=='X')break;
		if(a[x+i][y]=='.'&&vis[x+i][y]==1)return 0;
		//vis[x+i][y]=1;
	}
	for(int i=0;i<n;++i)
	{
		if(!in(x-i,y))break;
		if(a[x-i][y]=='X')break;
		if(a[x-i][y]=='.'&&vis[x+i][y]==1)return 0;
		//vis[x-i][y]=1;
	}
	for(int i=0;i<n;++i)
	{
		if(!in(x,y+i))break;
		if(a[x][y+i]=='X')break;
		if(a[x][y+i]=='.'&&vis[x+i][y]==1)return 0;
		//vis[x][y+i]=1;
	}
	for(int i=0;i<n;++i)
	{
		if(!in(x,y-i))break;
		if(a[x][y-i]=='X')break;
		if(a[x][y-i]=='.'&&vis[x+i][y]==1)return 0;
		//vis[x][y-i]=1;
	}
	return 1;
}

void paint(int x,int y)
{
	for(int i=0;i<n;++i)
	{
		if(!in(x+i,y))break;
		if(a[x+i][y]=='X')break;
		//if(a[x+i][y]=='.'&&vis[x+i][y]==1)return 0;
		vis[x+i][y]=1;
	}
	for(int i=0;i<n;++i)
	{
		if(!in(x-i,y))break;
		if(a[x-i][y]=='X')break;
		//if(a[x-i][y]=='.'&&vis[x+i][y]==1)return 0;
		vis[x-i][y]=1;
	}
	for(int i=0;i<n;++i)
	{
		if(!in(x,y+i))break;
		if(a[x][y+i]=='X')break;
		//if(a[x][y+i]=='.'&&vis[x+i][y]==1)return 0;
		vis[x][y+i]=1;
	}
	for(int i=0;i<n;++i)
	{
		if(!in(x,y-i))break;
		if(a[x][y-i]=='X')break;
		//if(a[x][y-i]=='.'&&vis[x+i][y]==1)return 0;
		vis[x][y-i]=1;
	}
}

int main()
{
	while(cin>>n)
	{
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i)scanf("%s",a[i]);
		int ans=0; 
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(a[i][j]=='.')
				{
					if(check(i,j))
					{
						paint(i,j);
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
