/* ***********************************************
Author        :kuangbin
Created Time  :2013/8/17 4:04:42
File Name     :F:\2013ACM练习\专题学习\数链剖分\POJ3237Tree.cpp
************************************************ */

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
int top[MAXN];//top[v] 表示v所在的重链的顶端节点
int fa[MAXN];//父亲节点
int deep[MAXN];//深度
int num[MAXN];//num[v] 表示以v为根的子树的节点数
int p[MAXN];//p[v]表示v对应的位置
int fp[MAXN];//fp和p数组相反
int son[MAXN];//重儿子
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

//线段树
#define X first
#define Y second
#define ll long long
int l[MAXN],r[MAXN];
ll sum[MAXN],Max[MAXN];
int a[MAXN];

void push_up(int x)
{
	sum[x]=sum[x<<1]+sum[x<<1|1];
	Max[x] = max(Max[x<<1],Max[x<<1|1]);
}

void build(int i,int L,int R)
{
	l[i]=L;r[i]=R;
	if(R==L+1)
	{
		sum[i]=a[L];
		Max[i] = a[L];
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
		return;
	}
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

ll query_max(int i,int L,int R)
{
	if(L==l[i]&& R==r[i])
		return Max[i];
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
    /*if(u==v){
    	tmp = query_max(1,p[u],p[u]+1);
	}*/
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
    if(deep[u] > deep[v]) swap(u,v);
    return max(tmp,query_max(1,p[u],p[v]+1));
}

ll find_sum(int u,int v)
{
	int f1 = top[u], f2 = top[v];
    ll tmp = 0;
	/*if(u==v){
    	tmp = query_sum(1,p[u],p[u]+1);
	}*/
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        tmp += query_sum(1,p[f1],p[u]+1);
        u = fa[f1]; f1 = top[u];
    }
    //if(u == v)return tmp;
    if(deep[u] > deep[v]) swap(u,v);
    return tmp+query_sum(1,p[u],p[v]+1);
}

int main()
{
	//freopen("input.in","r",stdin);
    int n;
    while(cin>>n)
    {
        init();
        int u,v;
        for(int i = 0;i < n-1;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,0,0);
        getpos(1,1);
        for(int i=1;i<=n;++i){
        	scanf("%d",&a[p[i]]);
		}
        build(1,1,n+1);
        int m;
        cin>>m;
        
        char str[20];
        while(m--){
        	scanf("%s",str);
        	//cout<<str<<endl;
        	scanf("%d%d",&u,&v);
        	if(str[0] == 'C')
        		update(1,p[u],p[u]+1,v);
			else {
				if(str[1] == 'S')
					printf("%d\n",find_sum(u,v));
				else 
					printf("%d\n",find_max(u,v));
			}
		}
        
    }
    return 0;
}
