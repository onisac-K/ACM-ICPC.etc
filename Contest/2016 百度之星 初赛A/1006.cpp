#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long

vector<int>v[100005];
int vec[100005];
int vis[100005];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		int n,m;
		cin>>n>>m;
		for(int i=0;i<=n;++i)
		{
			vec[i]=0;
			vis[i]=0;
			v[i].clear();
		}
		int u,vv;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&u,&vv);
			v[u].push_back(vv);
			vec[vv]++;
		}
		priority_queue<int , vector<int>, less<int> > q;
		for(int i=1;i<=n;++i)
		{
			if(vec[i]==0)
			{
				q.push(i);
				vis[i]=1;
			}
		}
		ll ans = 0;
		int mi=999999;
		while(!q.empty())
		{
			int u = q.top();
			//cout<<u<<endl;
			q.pop();
			mi=min(mi,u);
			ans += mi;
			for(int i=0;i<v[u].size();++i)
			{
				int k = v[u][i];
				if(vis[k]==1)continue;
				else 
				{
					vec[k]--;
					if(vec[k]==0)
					{
						vis[k]=1;
						q.push(k);
					}					
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
