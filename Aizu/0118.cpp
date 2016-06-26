#include<bits/stdc++.h>
using namespace std;

char a[105][105];
int vis[105][105];
int n,m;

void dfs(int x,int y,char c)
{
	//cout<<c<<endl;
	//cout<<x<<' '<<y<<' '<<a[x][y]<<' '<<vis[x][y]<<endl;	
	if(y>=m||y<0||x>=n||x<0||vis[x][y]!=0||a[x][y]!=c)return ;
	//cout<<123<<endl;
	vis[x][y]=1;
	dfs(x+1,y,c);dfs(x-1,y,c);dfs(x,y+1,c);dfs(x,y-1,c);
}

void debug()
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cout<<vis[i][j]<<' ';	
		}
		cout<<endl;
	}
}

int main()
{
	while(cin>>n>>m)
	{
		if(n==0 && m==0)break;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i)scanf("%s",a[i]);
		int ans=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(!vis[i][j])
				{
					ans++;
					dfs(i,j,a[i][j]);
					//debug();
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
