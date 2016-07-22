#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

#define PII pair<int,int>
#define VII vector<PII>
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)

const int N = 1500; 

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

int u[100005],v[100005],d[100005];
int dist[1005];

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	init(n);
	
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&u[i],&v[i],&d[i]);
		u[i]--;
		v[i]--;
		add_edge(u[i],v[i],d[i]);
	}
	dijkstra(k-1,n);
	for(int i=0;i<n;++i){
		dist[i]=dis[i];
	}
	
	init(n);
	for(int i=0;i<m;++i){
		add_edge(v[i],u[i],d[i]);
	}
	dijkstra(k-1,n);
	int ans = 0;
	for(int i=0;i<n;++i){
		if(dist[i]==INF || dis[i]==INF)continue;
		ans = max(ans,dis[i]+dist[i]); 
	}
		
	cout<<ans<<endl;
	return 0;
}


