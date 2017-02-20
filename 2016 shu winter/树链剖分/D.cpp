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
const int MAXN = 100010*4;
int head[MAXN],edge[MAXN][3];//记录边便于更改
int top[MAXN];//top[v]表示v所在的重链的顶端节点
int fa[MAXN]; //父亲节点
int deep[MAXN];//深度
int num[MAXN];//num[v]表示以v为根的子树的节点数
int p[MAXN];//p[v]表示v与其父亲节点的连边在线段树中的位置
int fp[MAXN];//和p数组相反
int son[MAXN];//重儿子
int pos,tot;

struct Edge
{
	int to,next;
}e[MAXN*2];

void init(int n)
{
	tot = 0;
	memset(head,-1,sizeof(head));
	pos =1;
	memset(son,-1,sizeof(son));
}
void addedge(int u,int v)
{
	e[tot].to = v; 
	e[tot].next = head[u]; 
	head[u] = tot++;
}
void dfs1(int u,int pre,int d) //第一遍dfs求出fa,deep,num,son
{
	deep[u] = d;
	fa[u] = pre;
	num[u] = 1;
	for(int i = head[u];i != -1; i = e[i].next)
	{
		int v = e[i].to;
		if(v != pre)
		{
			dfs1(v,u,d+1);
			num[u] += num[v];
			if(son[u] == -1 || num[v] > num[son[u]])
			son[u] = v;
		}
	}
}
void getpos(int u,int sp) //第二遍dfs求出top和p
{
	top[u] = sp;
	p[u] = pos++;
	fp[p[u]] = u;
	if(son[u] == -1) return;
		getpos(son[u],sp);
	for(int i = head[u];i != -1; i = e[i].next)
	{
		int v = e[i].to;
		if(v != son[u] && v != fa[u])
			getpos(v,v);
	}
}


//????ê÷
#define X first
#define Y second
#define ll long long
int l[MAXN],r[MAXN];
ll sum[MAXN],Max[MAXN];
ll Min[MAXN];
int a[MAXN];
int lazy[MAXN];
void push_up(int x)
{
	if(x == 1){
		sum[x] = sum[x<<1|1];
		Max[x] = Max[x<<1|1];
		Min[x] = Min[x<<1|1];
		return ;
	}
	sum[x]=sum[x<<1]+sum[x<<1|1];
	Max[x] = max(Max[x<<1],Max[x<<1|1]);
	Min[x] = min(Min[x<<1],Min[x<<1|1]);
}

void update_node(int x)
{
	ll tmp = Max[x];
	Max[x] = -1*Min[x];
	Min[x] = -1*tmp;
	lazy[x] ^= 1;	
}

void push_down(int x)
{
	if(lazy[x] == 0)return ;
	update_node(x<<1);
	update_node(x<<1|1);	
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
		sum[i] = val;
		Max[i] = val;
		Min[i] = val;
		lazy[i] = 0;
		return;
	}push_down(i);
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

void update2(int i,int L,int R)
{
	if(L==l[i] && R==r[i])
	{
		update_node(i);
		return;
	}
	push_down(i);
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		update2(i<<1,L,R);
	else if(L>=mid)
		update2(i<<1|1,L,R);
	else
	{
		update2(i<<1,L,mid);
		update2(i<<1|1,mid,R);
	}
	push_up(i);
}

ll query_max(int i,int L,int R)
{
	if(L==l[i]&& R==r[i]){
		//push_down(i);
		return Max[i];
	}
	push_down(i); 
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		return query_max(i<<1,L,R);
	else if(L>=mid)
		return query_max(i<<1|1,L,R);
	else
		return max(query_max(i<<1,L,mid),query_max(i<<1|1,mid,R));
	push_up(i);
}

ll query_sum(int i,int L,int R)
{
	if(L==l[i] && R==r[i])
		return sum[i];
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		return query_sum(i<<1,L,R);
	else if(L>=mid)
		return query_sum(i<<1|1,L,R);
	else
		return query_sum(i<<1,L,mid)+query_sum(i<<1|1,mid,R);
	push_up(i);
}

ll find_max(int u,int v)
{
	int f1 = top[u], f2 = top[v];
    ll tmp = -100000000;
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        } 
        tmp = max(tmp,query_max(1,p[f1],p[u]+1));
        u = fa[f1]; f1 = top[u];
    }
    if(u == v)return tmp;
    if(deep[u] > deep[v]) swap(u,v);
    return max(tmp,query_max(1,p[son[u]],p[v]+1));
}

ll find_sum(int u,int v)
{	
	int f1 = top[u], f2 = top[v];
    ll tmp = 0;
    while(f1 != f2){
        if(deep[f1] < deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }   
        tmp += query_sum(1,p[f1],p[u]+1);
        u = fa[f1]; f1 = top[u];
    }   
    if(u == v)return tmp;
    if(deep[u] > deep[v]) swap(u,v);
    return tmp+query_sum(1,p[son[u]],p[v]+1);
}

void nagate(int u, int v)
{
	int f1 = top[u], f2 = top[v];
    while(f1 != f2){
        if(deep[f1] < deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }   
        //tmp += query_sum(1,p[f1],p[u]+1);
        update2(1,p[f1],p[u]+1);
        u = fa[f1]; f1 = top[u];
    }   
    if(u == v)return;
    if(deep[u] > deep[v]) swap(u,v);
    update2(1,p[son[u]],p[v]+1);
}

void debug()
{
	for(int i=1;i<=10;++i)cout<<lazy[i] <<' ';cout<<endl;
	for(int i=1;i<=10;++i)cout<<Max[i] <<' ';cout<<endl;
	for(int i=1;i<=10;++i)cout<<Min[i] <<' ';cout<<endl;
	cout<<endl;
}

int val[MAXN];
int main()
{
//	freopen("input.in","r",stdin);
    int n,m,st;
    int t;
	cin>>t; 
    while(t--)
    {
    	cin>>n;
    	memset(Max,0,sizeof Max);
    	memset(Min,0x3f3f3f3f,sizeof Min);
    	memset(lazy,0,sizeof lazy);
        init(n);
        int u,v;
		for(int i=1;i<n;i++)
		{
			scanf("%d %d %d",&edge[i][0],&edge[i][1],&edge[i][2]);
			addedge(edge[i][0],edge[i][1]);
			addedge(edge[i][1],edge[i][0]);
		}
        dfs1(1,0,0);
        getpos(1,1);
     //   cout<<pos<<' '<<n<<endl;
        build(1,1,pos);
		for(int i=1;i<n;i++)
		{
			//cout<<i<<endl;
			if(deep[edge[i][0]]>deep[edge[i][1]])
				swap(edge[i][0],edge[i][1]);
			update(1,p[edge[i][1]],p[edge[i][1]]+1,edge[i][2]);
			
		}
	//	debug();
		char str[100];
		int op; 
        while(1){
        	scanf("%s",str);
        	if(str[0] == 'D')break;
        	scanf("%d%d",&u,&v);
        	
			if(str[0] == 'Q'){
        		printf("%d\n",find_max(u,v));
			}
			else if(str[0] == 'C') {
				update(1,p[edge[u][1]],p[edge[u][1]]+1,v);
			}
			else {
				nagate(u,v);
			}
		//	debug();
		}
        
    }
    return 0;
}
