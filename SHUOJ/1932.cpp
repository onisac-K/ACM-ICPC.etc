#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define PII pair<int,int>
#define VII vector<PII>
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
vector<PII> G[N];
int vis[N],dis[N];
int ans[N];

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
        for(int i=0;i<n;++i)ans[i] = -1;
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
                ans[y]=x;
            }
        }
    }
}
 
int dfs(int tt)
{
    if(ans[tt]==-1)
    {
        printf("%d",tt+1);
        return 0;
    }
    dfs(ans[tt]);
    printf(" %d",tt+1);
     
}
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;        
        scanf("%d%d",&n,&q);
        init(n);
        int a,b;
        for(int i=0;i<n-1;++i)
        {
            scanf("%d%d",&a,&b);
            a--;b--;
            add_edge(a,b,1);
            add_edge(b,a,1);
        }
        int s,t;
        for(int i=0;i<q;++i)
        {
            scanf("%d%d",&s,&t);
            s--;
            t--;
            dijkstra(s,n);
         
            dfs(t);
            cout<<endl;
        }
    }
    return 0;
}
