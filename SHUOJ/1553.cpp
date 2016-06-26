#include<bits/stdc++.h>
using namespace std;
 
int n,m;
int a[105][105];
int vis[105][105];
int d[4][2]={1,0,-1,0,0,1,0,-1};
int dp[105][105]; 

bool in(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m)return false;
}

int dfs(int i,int j)
{
	if(dp[i][j])return dp[i][j];
	int ans=0;
	for(int k=0;k<4;++k)
	{
		int x=i+d[k][0];
		int y=j+d[k][1];
		
		if(in(x,y)&&a[x][y]<a[i][j])
		{
			dp[i][j]=max(dp[i][j],dfs(x,y)+1);
		}
	}
	return dp[i][j];
}
 
void debug()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)cout<<dp[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}
 
int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)scanf("%d",&a[i][j]);
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {               
                ans=max(dfs(i,j),ans);
                debug();
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
