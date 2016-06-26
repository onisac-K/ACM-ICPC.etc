#include <iostream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <ctime>
using namespace std;
#define XINF INT_MAX
#define INF (0x3f3f3f3f)
#define MAXN (200)
#define eps (1e-10)
#define zero(a) (fabs(a)<eps)
#define sqr(a) ((a)*(a))
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define PF(X) push_front(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define PI  acos(-1.0)
#define test puts("OK");
#define lowbit(X) (X&(-X))
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef pair<int,int> PII;
typedef priority_queue<int,vector<int>,greater<int> > PQI;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
 
struct edge
{
    int to,next,id;
} edges[2*MAXN],query[2*MAXN];
 
int head[MAXN],cnt;
int headq[MAXN],cntq;
 
void addedge(edge *ed,int *he,int &ct,int x,int y,int pos=0)
{
    edge &e=ed[ct];
    e.to=y;e.next=he[x];
    e.id=pos;
    he[x]=ct++;
}
 
bool used[MAXN];
int par[MAXN];
int ans[MAXN];
 
int find(int x)
{
    return (par[x]==-1)?(x):(par[x]=find(par[x]));
}
 
void dfs(int u,int fa)
{
    used[u]=1;
    for(int j=headq[u];j!=-1;j=query[j].next)
    {
        int v=query[j].to;
        if(used[v])
            ans[query[j].id]=find(v);
    }
    for(int j=head[u];j!=-1;j=edges[j].next)
    {
        int v=edges[j].to;
        if(v!=fa)
            dfs(v,u);
    }
    par[u]=fa;
}
 
int main()
{_
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,ca=1;
    scanf("%d",&T);
    while(T--)
    {
        CLR(head,-1);cnt=0;
        CLR(headq,-1);cntq=0;
        CLR(par,-1);CLR(used,0);
        int n;
        scanf("%d",&n);
        REP(i,n)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            addedge(edges,head,cnt,x,y);
            addedge(edges,head,cnt,y,x);
        }
        int q;
        scanf("%d",&q);
        REP(i,q)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            addedge(query,headq,cntq,x,y,i);
            addedge(query,headq,cntq,y,x,i);
        }
        dfs(0,-1);
        printf("Case %d:\n",ca++);
        REP(i,q)
            printf("%d%c",ans[i],i==q-1?'\n':' ');
    }
    return 0;
}
