#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define VII vector<PII>
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
const int N = 1000; 
vector<PII> G[N];
int vis[N],dis[N],par[N];

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
            	par[y] = x;
                dis[y] = dis[x] + d;
                q.push(MP(dis[y],y));
            }
        }
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		init(n);
		int u,v;
		for(int i=0;i<n-1;++i){
			cin>>u>>v;
			u--;v--;
			add_edge(u,v,1);
			add_edge(v,u,1);
		}
		for(int i=0;i<q;++i){
			cin>>u>>v;
			u--;v--;
			dijkstra(u,n);
			par[u] = -1;
			vector<int> ans;
			int F = v;
			ans.push_back(F+1);
			while(par[F] != -1){
				F = par[F];
				ans.push_back(F+1);
			}
			for(int i=ans.size()-1;i>=0;--i){
				printf("%d%c",ans[i],(i>0)? ' ':'\n');
			}
		}
	}
	return 0;
}

