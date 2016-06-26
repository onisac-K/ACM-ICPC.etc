#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[25][25];
int vis[25][25];
int n,m;

int dfs(int x,int y)
{
	if(y>=n||y<0||x>=m||x<0||vis[x][y]!=0||a[x][y]=='#')return 0;
	vis[x][y]=1;
	return 1+dfs(x+1,y)+dfs(x-1,y)+dfs(x,y+1)+dfs(x,y-1);
}

int main()
{
	while(cin>>n>>m)
	{
		if(n==0&&m==0)break;
		memset(vis,0,sizeof(vis));
		int tx=0,ty=0;
		int f=0;
		for(int i=0;i<m;++i)scanf("%s",a[i]);
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(a[i][j]=='@')
				{
					tx=i;
					ty=j;
					f=1;
					break;
				}
			}
			if(f==1)break;
		}
		cout<<dfs(tx,ty)<<endl;
	}
	return 0;
} 
