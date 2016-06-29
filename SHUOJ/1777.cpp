#include<bits/stdc++.h>
using namespace std;

 
#define PII pair<int,int>
#define VII vector<PII>
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
const int N = 1005; 
vector<PII> G[N];
int vis[N],dis[N];

void add_edge(int u,int v,int d){
    G[u].PB(MP(v,d));
}

void init(int n){
    for(int i=0;i<=n;i++){
        G[i].clear();
    }
}

void dijkstra(int s,int n){
  		for(int i=0;i<n;i++)vis[i] = 0;
for(int i=0;i<n;i++)dis[i] = (i == s ? 0 : INF);
   		priority_queue<PII,VII,greater<PII> >q;
    	q.push(MP(dis[s],s));
    	while(!q.empty()){
        PII p = q.top();
        int x = p.second;
        q.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i].first;
            int d = G[x][i].second;
            if(!vis[y]&&dis[x] + d < dis[y]){
                dis[y] = dis[x] + d;
                q.push(MP(dis[y],y));
            }
        }
    }
}

int main()
{
	int n,m,k;
	int u,v,d;
	int f=1;
	while(cin>>n>>m>>k)
	{
		init(n+1);
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&u,&v,&d);
			add_edge(u,v,d);
			add_edge(v,u,d);
		}
		cout<<"Case "<<f++<<endl;
		for(int i=0;i<k;++i)
		{
			int s,t;
			scanf("%d%d",&s,&t);
			dijkstra(s,n);
			cout<<((dis[t]==INF)? -1:dis[t])<<endl;
		}
	}
	return 0;
}




