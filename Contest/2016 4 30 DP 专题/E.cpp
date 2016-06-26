#include<bits/stdc++.h>
using namespace std;

int piece[1<<16];
int dp[1<<16][105];
int vis[1<<16][105];
int n;

int dfs(int s,int b)
{
	if(vis[s][b]==1)return dp[s][b];	
	vis[s][b]=1;
	if(piece[s]==0)return 0;
	for(int i=0;i<n;++i)
	{
		if(s==(1<<i))return dp[s][b]=1;
	}
	int a = piece[s]/b;
	for(int i=s;i;i=(i-1)&s)
	{
		int s1 = piece[i];
		int s2 = piece[s]-piece[i];
		int j = i ^ s;
		if(s1%b==0 && s2%b==0 && dfs(i,min(b,s1/b)) && dfs(j,min(b,s2/b)))
			return dp[s][b]=1;
		if(s1%a==0 && s2%a==0 && dfs(i,min(a,s1/a)) && dfs(j,min(a,s2/a)))
			return dp[s][b]=1;	
	}
	return dp[s][b]=0;
}

int main()
{
	int f=1;
	while(cin>>n&&n)
	{
		int x,y;
		cin>>x>>y;
		memset(dp,0,sizeof(dp));
		memset(piece,0,sizeof(piece));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i)cin>>piece[1<<i];
		for(int i=0;i<(1<<n);++i)
		{
			for(int j=0;j<n;++j)
			{
				if(i==(1<<j))break;
				if(i&(1<<j))
				{					
					piece[i]+=piece[1<<j];
				}
			}
		}
		//cout<<piece[(1<<n)-1]<<endl;
		printf("Case %d: ",f++);
		if(piece[(1<<n)-1]!=x*y){
			cout<<"No"<<endl;
		}
		else 
		{
			cout<<((dfs((1<<n)-1,min(x,y))==1)? "Yes":"No" )<<endl;
		}
	}
	return 0;
}

/*
4
3 4 
6 3 2 1
2 
2 3
1 5
0
*/
