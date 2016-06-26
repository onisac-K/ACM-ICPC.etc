#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int step,steps,tx,ty,ex,ey;
int a[30][30];
int n,m;
int d[4][2]={1,0,-1,0,0,1,0,-1};

void dfs(int x,int y)
{
	if(step>10)return ;
	for(int i=0;i<4;++i)
	{
		int ok=0;
		int nx=x+d[i][0];
		int ny=y+d[i][1];
		while(nx>=0&&nx<n&&ny>=0&&ny<m&&a[nx][ny]!=1)
		{
			ok=1;
			if(nx==ex && ny==ey)steps=min(steps,step);
			nx+=d[i][0];
			ny+=d[i][1];
		}
		if(ok==1&&a[nx][ny]==1)
		{
			a[nx][ny]=0;step++;
			dfs(nx-d[i][0],ny-d[i][1]);
			a[nx][ny]=1;
			step--;
		}
	}
}
int main()
{
	while(~scanf("%d%d",&m,&n)&&n&&m)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				cin>>a[i][j];
				if(a[i][j]==2)
				{
					tx=i;ty=j;
				}
				if(a[i][j]==3)
				{
					ex=i;ey=j;
				}
			}
		}
		step=1;steps=1000000;
		dfs(tx,ty);
		cout<<((steps>=1&&steps<=10)? steps:-1 )<<endl;
	}
	return 0;
} 
