#include<bits/stdc++.h> 
using namespace std;
#define INF 0x3F3F3F3F

int d[4][2]={1,0,-1,0,0,1,0,-1};
char a[5][5];
int p[4][4];
int n,m,tx,ty,c;
int dp[1<<16][25][25];


int dfs(int v,int x,int y)
{
	
	if(v==(1<<c)-1)return 0;
	int &flag=dp[v][x][y];
//	cout<<flag<<endl;
	if(flag!=-1)return flag;
	flag = INF;
	int ans=INF;
	for(int i=0;i<4;++i)
	{
		int tx=x/4+d[i][0];
		int ty=x%4+d[i][1];
		if(tx<0||ty<0||tx>=n||ty>=m||a[tx][ty]=='X')continue;
		for(int j=0;j<4;++j)
		{
			int tx2=y/4+d[j][0];
			int ty2=y%4+d[j][1];
			if(tx2<0||ty2<0||tx2>=n||ty2>=m||a[tx2][ty2]=='X')continue;
			ans=min(ans,1+dfs(v|(1<<p[tx][ty])|(1<<p[tx2][ty2]),tx*4+ty,tx2*4+ty2));
		}
	}
	return flag = ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		c=0;
		for(int i=0;i<n;++i)
			scanf("%s",a[i]);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(a[i][j]=='S')
				{
					//cout<<i<<' '<<j<<endl;
					tx=i;
					ty=j;
				}
				if(a[i][j]=='S'||a[i][j]=='O')p[i][j]=c++;
			}
		}
		//cout<<tx<<' '<<ty<<endl;
		for(int i=0;i<(1<<c);++i)
		{
			for(int j=0;j<25;++j)
				for(int k=0;k<25;++k)dp[i][j][k]=-1;
		}
		cout<<dfs(1<<p[tx][ty],tx*4+ty,tx*4+ty)<<endl;
		/*for(int i=0;i<(1<<c);++i)
		{
			for(int j=0;j<25;++j)
				for(int k=0;k<25;++k)cout<<dp[i][j][k]<<endl;
		}*/
		//cout<<dfs(1<<p[tx][ty],tx*4+ty,tx*4+ty)<<endl;
	}
	return 0;
}
 
