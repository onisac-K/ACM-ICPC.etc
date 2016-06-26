#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int ans[16][16];
int a[16][16];
int b[16][16];
int d[4][2]={1,0,0,1,-1,0,0,-1};
int n,m;

void paint(int x,int y)
{
	if(b[x][y]==0)b[x][y]=1;
	else b[x][y]=0;
	for(int i=0;i<4;++i)
	{
		int tx=x+d[i][0];
		int ty=y+d[i][1];
		if(tx<0||ty<0||tx>=n||ty>=m)continue;
		if(b[tx][ty]==0)b[tx][ty]=1;
		else b[tx][ty]=0;
	}
}

void Debug()
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}

bool solve(int s)
{
	//cout<<s<<endl;
	memset(ans,0,sizeof(ans));
	memcpy(b,a,sizeof(a));
	
	for(int i=0;i<m;++i)
	{
		if(s&(1<<i))
		{
			ans[0][i]=1;
		}
	}
	/*for(int i=0;i<m;++i)cout<<ans[0][i]<<' ';
	cout<<endl;*/
	
	for(int i=0;i<m;++i)
	{
		if(ans[0][i]==1)paint(0,i);
	}
	for(int i=0;i<n-1;++i)
	{
		//Debug();
		for(int j=0;j<m;++j)
		{
			if(b[i][j]==1)
			{
				paint(i+1,j);
				ans[i+1][j]=1;
			}
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(b[i][j]==1)return 0;
		}
	}
	return 1;
}

int main()
{
	while(cin>>n>>m)
	{
		int flag=1;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)scanf("%d",&a[i][j]);
		}
		for(int i=0;i<(1<<m);++i)
		{
			if(solve(i))
			{
				for(int j=0;j<n;++j)
				{
					for(int k=0;k<m;++k)
					{
						if(k<m-1)printf("%d ",ans[j][k]);
						else printf("%d\n",ans[j][k]);
					}
				}
				flag=0;
				break;
			}
			
		}
		if(flag)printf("IMPOSSIBLE\n");
	}
	return 0;
}
