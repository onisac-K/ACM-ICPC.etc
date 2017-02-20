#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAXN = 50010*4;
struct Edge
{
	int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN];
int fa[MAXN];
int deep[MAXN];
int num[MAXN];
int p[MAXN];
int fp[MAXN];
int son[MAXN];
int pos;
void init()
{
	tot = 0;
	memset(head,-1,sizeof(head));
	pos = 1;
	memset(son,-1,sizeof(son));
}
void addedge(int u,int v)
{
	edge[tot].to = v; edge[tot].next = head[u]; head[u] = tot++;
}
void dfs1(int u,int pre,int d)
{
	deep[u] = d;
	fa[u] = pre;
	num[u] = 1;
	for(int i = head[u];i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if(v != pre)
		{
			dfs1(v,u,d+1);
			num[u] += num[v];
			if(son[u] == -1 || num[v] > num[son[u]])
				son[u] = v;
		}
	}
}
void getpos(int u,int sp)
{
	top[u] = sp;
	p[u] = pos++;
	fp[p[u]] = u;
	if(son[u] == -1) return;
	getpos(son[u],sp);
	for(int i = head[u];i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		if( v != son[u] && v != fa[u])
		getpos(v,v);
	}
}


#define X first
#define Y second
#define ll long long
int l[MAXN],r[MAXN];
int sum[MAXN];
int lazy[MAXN];
int a[MAXN];

void push_up(int x)
{
	sum[x]=sum[x<<1]+sum[x<<1|1];
}

void update_node(int x,int val)
{
	sum[x] += (r[x]-l[x])*val;
	lazy[x] += val;
}

void push_down(int x)
{
	update_node(x<<1,lazy[x]);
	update_node(x<<1|1,lazy[x]);
	lazy[x] = 0;
}

void build(int i,int L,int R)
{
	l[i]=L;r[i]=R;
	if(R==L+1)
	{
		sum[i]=a[L];
		return;
	}
	int mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid,R);
	push_up(i);
}

void update(int i,int L,int R,int val)
{
	if(L==l[i] && R==r[i])
	{
		update_node(i,val);
		return;
	}
	push_down(i);
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		update(i<<1,L,R,val);
	else if(L>=mid)
		update(i<<1|1,L,R,val);
	else
	{
		update(i<<1,L,mid,val);
		update(i<<1|1,mid,R,val);
	}
	push_up(i);
}

void add(int u,int v,int val)
{
	int f1 = top[u], f2 = top[v]; 
	//cout<<f1<<' '<<f2<<endl;
	while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        } 
        update(1,p[f1],p[u]+1,val);
        u = fa[f1]; f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u,v);
	update(1,p[u],p[v]+1,val);
}

ll query(int i,int L,int R)
{
	if(L==l[i]&& R==r[i])
	{
		return sum[i];
	}
	push_down(i);
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		return query(i<<1,L,R);
	else if(L>=mid)
		return query(i<<1|1,L,R);
	push_up(i);
}
void debug()
{
	for(int i=1;i<10;++i)cout<<lazy[i]<<' ';cout<<endl;
	for(int i=1;i<10;++i)cout<<sum[i]<<' ';cout<<endl;

}

int val[MAXN];
int main()
{
	//freopen("1.in","r",stdin);
    int n,m,P;
    while(cin>>n>>m>>P)
    {
        init();
        memset(lazy,0,sizeof lazy);
        int u,v,d;
        for(int i=1;i<=n;++i)scanf("%d",&val[i]); 
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,0,0);
        getpos(1,1);
        for(int i=1;i<=n;++i){
        	a[p[i]] = val[i];
		}
        build(1,1,n+1);
        char str[20];
        while(P--){
        	scanf("%s",str);
        	if(str[0] == 'I'){
        		scanf("%d%d%d",&u,&v,&d);
        		add(u,v,d);
			}
			else if(str[0] == 'D'){
        		scanf("%d%d%d",&u,&v,&d);
        		add(u,v,-1*d);
			}
			else {
				scanf("%d",&u);
				printf("%d\n",query(1,p[u],p[u]+1));
			}
		//	debug();
		//	cout<<endl;
		}
        
    }
    return 0;
}
