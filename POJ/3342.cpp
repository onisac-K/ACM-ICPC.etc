#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<map> 
#include<string>
#include<set>
using namespace std;
const int N = 305;

int dp[N][2];
int dup[N][2];
int vis[N];
int pa[N];
int n;
int k;
map <string,int>name;

void dfs(int i)
{
	//cout<<i<<endl;
	if(vis[i])return ;
	vis[i]=1;
	for(int j=0;j<n;++j)
	{
		if(vis[j])continue;
		if(pa[j]==i)
		{
			dfs(j);
			//if(dp[j][0]==dp[j][1])dup[i][0]=1;
			dp[i][0]+=max(dp[j][0],dp[j][1]);
			if(dp[j][0]>dp[j][1]&&dup[j][0]==1)dup[i][0]=1;
			if(dp[j][0]<dp[j][1]&&dup[j][1]==1)dup[i][0]=1;
			if(dp[j][0]==dp[j][1])dup[i][0]=1;			
			dp[i][1]+=dp[j][0];
			if(dup[j][0]==1)dup[i][1]=1;
		}
	}
}

int main()
{
	while(cin>>n&&n)
	{
		name.clear();
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		memset(dup,0,sizeof(dup));
		memset(pa,0,sizeof(pa));
		string s;
		string u,v;
		cin>>s;
		k=0;
		name[s]=k++;
		pa[name[s]]=-1;
		for(int i=0;i<n-1;++i)
		{
			cin>>u>>v;
			if(!name.count(u))name[u]=k++;
			if(!name.count(v))name[v]=k++;
			pa[name[u]]=name[v];
		}
		for(int i=0;i<n;++i)dp[i][1]=1;
		dfs(name[s]);
		int ans=max(dp[name[s]][0],dp[name[s]][1]);
		cout<<ans<<" ";
		/*int f=1;
		for(int i=0;i<n;++i)
		{
			if(dp[i][0]==dp[i][1])
			{
				for(int j=0;j<n;++j)
				{
					if(pa[j]==i)
					{
						if(dp[j][0]==dp[j][1])
						{
							f=0;break;
						}
					}
				}
				if(f==0)break;
			}
		}*/
		if(dp[name[s]][0]>dp[name[s]][1]&&dup[0][0]==1)cout<<"No"<<endl;
		else if(dp[name[s]][0]<dp[name[s]][1]&&dup[0][1]==1)cout<<"No"<<endl;
		else if(dp[name[s]][0]==dp[name[s]][1])cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
		//cout<<dp[0][0]<<' '<<dp[0][1]<<endl;
		//cout<<f<<endl;
		//cout<<((f==0)? "No":"Yes")<<endl;
	}
 } 
