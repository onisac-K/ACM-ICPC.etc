#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,k;
char a[10][10];
int vis[15];
int ans=0;

void dfs(int num,int c)
{
	if(c==k)
	{
		/*for(int j=0;j<n;++j)if(vis[j]==1)cout<<j<<' ';
		cout<<endl;*/
		ans++;
		return ;
	}
	//if(num>=n)return ;
	for(int i=num;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(a[i][j]=='#'&&vis[j]==0)
			{
				//cout<<i<<' '<<j<<endl;
				vis[j]=1;
				dfs(i+1,c+1);
				vis[j]=0;
			}
		}
	}
}

int main()
{
	while(scanf("%d%d",&n,&k)!=EOF&&!(n==-1&&k==-1))
	{
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i)scanf("%s",a[i]);
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;
}
