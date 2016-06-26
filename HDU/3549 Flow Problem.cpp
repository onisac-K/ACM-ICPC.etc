#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define maxn 18
#define INF 0x3f3f3f3f

struct Edge
{
    int from, to, cap;
};

vector<Edge> EG;
vector<int> G[maxn];
int n, s, t, ans, d[maxn], cur[maxn];

void addEdge(int from, int to, int cap)
{
    EG.push_back((Edge){from, to, cap});
    EG.push_back((Edge){to, from, 0});
    int x = EG.size();
    G[from].push_back(x-2);
    G[to].push_back(x-1);
}

bool bfs()
{
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i = 0; i < G[x].size(); i++)
        {
            Edge& e = EG[G[x][i]];
            if(d[e.to] == -1 && e.cap > 0)
            {
                d[e.to] = d[x]+1;
                q.push(e.to);
            }
        }
    }
    return (d[t]!=-1);
}

int dfs(int x, int a)
{
    if(x == t || a == 0) return a;
    int flow = 0, f;
    for(int& i = cur[x]; i < G[x].size(); i++)
    {
        Edge& e = EG[G[x][i]];
        if(d[x]+1 == d[e.to] && (f = dfs(e.to, min(a, e.cap))) > 0)
        {
            e.cap -= f;
            EG[G[x][i]^1].cap += f;
            flow += f;
            a -= f;
            if(a == 0) break;
        }
    }
    return flow;
}
void Dinic()
{
    ans = 0;
    while(bfs())
    {
        memset(cur, 0, sizeof(cur));
        ans += dfs(s, INF);
    }
}
int main()
{
    //freopen("hdu_3549.txt", "r", stdin);
    int T, m, from, to, cap;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &n, &m);
        while(m--)
        {
            scanf("%d%d%d", &from, &to, &cap);
            addEdge(from, to, cap);
        }
        s = 1, t = n;
        Dinic();
        printf("Case %d: %d\n", cas, ans);
        EG.clear();
        for(int i = 0; i <= n; ++i)
            G[i].clear();
    }
    return 0;
}
