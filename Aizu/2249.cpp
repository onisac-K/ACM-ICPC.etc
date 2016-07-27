#include<bits/stdc++.h>
using namespace std; 

#define MAXN 20005*2
#define ll long long
const int INF = (1<<26);

struct node{
    int v, w;
    int next;
    int money; 
}edge[MAXN];

queue<int> q;
int dis[MAXN], head[MAXN], top, inq[MAXN], used[MAXN], cost[MAXN];


void add(int u, int v, int w,int m){
    edge[top].v = v;
    edge[top].w = w;
    edge[top].money = m;
    edge[top].next = head[u];
    head[u] = top++;
}

int spfa(int n){
    for(int i=1; i<=n; i++) dis[i] = INF;
    dis[1] = 0;
    q.push(1);
    used[1]++;
    while(!q.empty()){
        int x = q.front(); q.pop();
        inq[x] = 0;
        for(int u = head[x]; u != -1; u = edge[u].next){
            if(dis[edge[u].v] > dis[x]+edge[u].w){
                dis[edge[u].v] = dis[x]+edge[u].w;
                cost[edge[u].v] = edge[u].money;
                if(!inq[edge[u].v]){
                    inq[edge[u].v] = 1;
                    if(++used[edge[u].v] > n-1) return 0;
                    q.push(edge[u].v);
                }
            }
            else if(dis[edge[u].v] == dis[x]+edge[u].w){
            	if(cost[edge[u].v] > edge[u].money){
            		cost[edge[u].v] = edge[u].money;
	            	if(!inq[edge[u].v]){
	                    inq[edge[u].v] = 1;
	                    if(++used[edge[u].v] > n-1) return 0;
	                    q.push(edge[u].v);
	                }
				}
			}
        }
    }
    return 1;
}

void init(int n){
    top = 0;
    for(int i=1; i<=n; i++){
        inq[i] = 0;
        cost[i] = 0;
        used[i] = 0;
        head[i] = -1;
    }
}

int main()
{
	int n,m;
	while(cin>>n>>m && (n||m)){
		init(n);
		int u,v,d,y;
		for(int i=0;i<m;++i){
			scanf("%d%d%d%d",&u,&v,&d,&y);
			add(u,v,d,y);
			add(v,u,d,y);
		}
		spfa(n);
		ll val = 0;
		for(int i=1;i<=n;++i)val += cost[i];
		cout<<val<<endl;
		
	}
	return 0;
}

