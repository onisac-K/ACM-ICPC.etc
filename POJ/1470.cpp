#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=1000;

#define CLR(X,A) memset(X,A,sizeof(X))

int deep[maxn],pa[maxn],vis[maxn],fre[maxn];

vector<int> adj[maxn];
vector<int> que[maxn];

int init(int n)
{
	CLR(deep,0);
	CLR(vis,0);
	CLR(fre,0);
	for(int i=0;i<=n;++i)
	{
		pa[i]=i;
		adj[i].clear();
		que[i].clear();
	}	
}

int find(int x)
{
	return x==pa[x]? x:(pa[x]=find(pa[x]));
}

void dfs(int i)
{
	int sz=adj[i].size();
	for(int j=0;j<sz;++j)
	{
		int son=adj[i][j];
		dfs(son);
		pa[son]=i;
	}
	vis[i]=1;
	int ss=que[i].size();
	for(int j=0;j<ss;++j)
	{
		int son=que[i][j];
		if(vis[son])
		{
			int ans=find(son);
			fre[ans]++;
		}
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		init(n);
		int a,b,c;
		for(int i=0;i<n;++i)
		{
			scanf("%d:(%d)",&a,&b);
			while(b--)
			{
				scanf("%d",&c);
				deep[c]++;
				adj[a].push_back(c);
			}
		}
		//cout<<123<<endl;
		scanf("%d",&a);
		while(a--)
		{
			while(getchar()!='(');
			scanf("%d%d",&c,&b);
			que[c].push_back(b);
			que[b].push_back(c);
		}
		//cout<<123<<endl;
		while(getchar()!=')');
		for(int i=1;i<=n;++i)
		{
			if(deep[i]==0)
			{
				dfs(i);
				break;
			}
		}
		//cout<<123<<endl;
		for(int i=1;i<=n;++i)
		{
			if(fre[i])cout<<i<<':'<<fre[i]<<endl;
		}
	}
	return 0;
} 
