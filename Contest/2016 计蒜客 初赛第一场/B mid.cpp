#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define PII pair<int,int>
#define VII vector<PII>
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)

const int N = 10005; 
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

int a[10005];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	int u,v;
	init(n);
	for(int i=0;i<n-1;++i)
	{
		scanf("%d%d",&u,&v);
		u--;
		v--;
		add_edge(u,v,1);
		add_edge(v,u,1);
	}
	int ans = 0;
	for(int i=0;i<n;++i)
	{
		dijkstra(i,n);
		for(int j=i+1;j<n;++j)
		{
			if(__gcd(i+1,j+1)==1)
			{
				ans += dis[j];
			}
		}
	}
	cout<<ans<<endl;
}

