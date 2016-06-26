#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<vector>
using namespace std;
#define N 205
#define mem(A,x) memset(A,x,sizeof(A));

map<string,int> mp;
set<string> s;
string root;
string q[N];
int qnum=0;
int dp[N][2];// 1 yes 0 no
int pa[N],vis[N];
int n;

void dfs(string u)
{
	if(vis[mp[u]]==1)return;
	vis[mp[u]]=1;
	for(int i=0;i<qnum;++i)
	{
		if(vis[mp[q[i]]]==0&&pa[mp[q[i]]]==mp[u])
		{
			dfs(q[i]);
			dp[mp[u]][1]+=dp[mp[q[i]]][0];
			dp[mp[u]][0]+=max(dp[mp[q[i]]][0],dp[mp[q[i]]][1]);
		}
		
	}
}


int main()
{
	int n;
	while(cin>>n&&n)
	{
		mem(dp,0);
		mem(pa,0);
		mem(vis,0);
		mp.clear();
		s.clear();
		cin>>root;
		qnum=0;
		mp.insert(make_pair(root,0));
		s.insert(root);
		q[qnum++]=root;
		string a,par;
		int flag=1;
		
		for(int i=0;i<n-1;++i)
		{
			cin>>a>>par;
			if(!s.count(a))
			{
				s.insert(a);
				q[qnum++]=a;
				mp.insert(make_pair(a,flag++));
			}
			if(!s.count(par))
			{
				s.insert(par);
				q[qnum++]=par;
				mp.insert(make_pair(par,flag++));
			}
			pa[mp[a]]=mp[par];
		}
		for(int i=0;i<flag;++i)dp[i][1]=1;
		dfs(root);
		//cout<<root<<endl;
		//cout<<pa[mp["Joe"]]<<endl;
		int ans=max(dp[mp[root]][0],dp[mp[root]][1]);
		cout<<ans<<' ';
		int f=1;
		for(int i=0;i<n;++i)
		{
			if(dp[i][0]>dp[i][1])
			{
				for(int j=0;j<n;++j)
				{
					if(pa[j]==i)
					{
						if(dp[j][0]==dp[j][1])
						{
							f=0;
							break;
						}
					}
				}
			}
			if(f==0)break;
		}
		if(f==0||dp[0][0]==dp[0][1])cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}

