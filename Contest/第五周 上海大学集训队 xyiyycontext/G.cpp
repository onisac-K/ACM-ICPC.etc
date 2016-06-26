#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f
struct edge
{
	int to,cap,cost,rev;
	edge (int _to,int _cap,int _cost,int _rev)
	{
		to = _to;
		cap = _cap;
		cost = _cost;
		rev = _rev;
	}
};

int V;
vector<edge> G[510];
int dist[510];
int prevv[510];
int preve[510];

void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back((edge){to,cap,cost,G[to].size()});
	G[to].push_back((edge){from,0,-1*cost,G[from].size()-1});
}
int vis[510];
int min_cost_flow(int s,int t,int f)
{
	int res = 0;
	while(f>0)
	{
		//cout<<f<<endl;
		fill(dist,dist+V,INF);
		dist[s]=0;
		queue<int> q;
		memset(vis,0,sizeof(vis));
		q.push(s);
		while(!q.empty())
		{
			int v=q.front();
			cout<<v<<endl;
			q.pop();
			vis[v]=0;
			for(int i=0;i<G[v].size();++i)
			{
				edge &e =G[v][i];
				if(e.cap>0&&dist[e.to]>dist[v]+e.cost)
				{
					dist[e.to]=dist[v]+e.cost;
					prevv[e.to]=v;
					preve[e.to]=i;
					if(!vis[e.to])
					{
						q.push(e.to);
						vis[e.to] = 1;
					}
				}
			}
		}
		/*bool update = true ;
		while(update)
		{
			update = false ;
			for(int v=0;v<V;++v)
			{
				if(dist[v]==INF)continue;
				for(int i=0;i<G[v].size();++i)
				{
					edge &e = G[v][i];
					if(e.cap>0&&dist[e.to]>dist[v]+e.cost)
					{
						dist[e.to]=dist[v]+e.cost;
						prevv[e.to]=v;
						preve[e.to]=i;
						update = true ;
					}
				}
			}
		}*/
		//cout<<dist[t]<<' '<<INF<<endl;
		if(dist[t]==INF)
		{
			f=INF-f;
			//cout<<123<<endl;
			printf("%d %d",f,2*f-res);
			return -1;
		}
		int d=f;
		for(int v=t;v!=s;v=prevv[v])
		{
			//cout<<v<<endl;
			//break;
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		//cout<<123<<endl;
		f-=d;
		res+=d*dist[t];
		for(int v=t;v!=s;v=prevv[v])
		{
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
		//cout<<f<<endl;
	}
	cout<<f<<endl;
	printf("%d %d",f,2*f-res);
	return 1;
}

int gr[510*2];
int gi[510*2];
int g[510*2][510*2];
char a[510*2];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(g,0,sizeof(g));
		memset(gi,0,sizeof(gi));
		memset(gr,0,sizeof(gr));
		int n;
		cin>>n;
		int s=n;
		int t=n+1;
		scanf("%s",a);
		for(int i=0;i<n;++i)
			if(a[i]=='0')gr[i]=0;
			else gr[i]=1;
		scanf("%s",a);
		for(int i=0;i<n;++i)
			if(a[i]=='0')gi[i]=1;
			else gi[i]=0;
		int b,c;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&b);
			for(int j=0;j<b;++j)
			{
				scanf("%d",&c);
				c--;
				g[i][c]=1;
			}
		}
		for(int i=0;i<=t;++i)G[i].clear();
		for(int i=0;i<n;++i)
		{
			if(gr[i])add_edge(s,i,1,0);
			else add_edge(i,t,1,0);
		}
		for(int i=0;i<n;++i)
		{
			if(gr[i]==1)
			for(int j=0;j<n;++j)
			{
				if(gr[j]==1||g[i][j]==1||i==j)continue;
				add_edge(i,j,1,2-gi[i]-gi[j]);
			}
		}
		int ans=min_cost_flow(s,t,INF);
		for(int i=0;i<n;++i)
		{
			if(gr[i])
			{
				int sz=G[i].size();
				for(int j=0;j<sz;++j)
				{
					int u=G[i][j].to;
					if(gr[u])continue;
					if(u>=n)continue;
					int c=G[i][j].cap;
					if(c==0)
					{
						printf("%d %d",i+1,u+1);
					}
				}
			}
		}
	}
}
