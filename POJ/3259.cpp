#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

struct edge{
	int from,to,cost;	
};
edge es[6000];
int d[505];
int V,E;

void shortest_path(int s){
	for(int i=0;i<V;++i)d[i] = INF;
	d[s] = 0;
	while(true){
		bool update = false;
		for(int i=0;i<E;++i){
			edge e = es[i];
			if(d[e.from] != INF && d[e.to]>d[e.from]+e.cost){
				d[e.to] = d[e.from]+e.cost;
				update = true;
			}
		}
		if(!update)break;
	}
}

bool findloop(){
	memset(d,0,sizeof(d));
	for(int i=0;i<V;++i){
		for(int j=0;j<E;++j){
			edge e = es[j];
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to] = d[e.from]+e.cost;
				if(i==V-1)return true;
			} 
		}
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,w;
		cin>>n>>m>>w;
		int u,v,d;
		V = n;
		E = 0;
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&u,&v,&d);
			es[E].cost=d;
			es[E].from=u;
			es[E++].to=v;	
			es[E].cost=d;
			es[E].from=v;
			es[E++].to=u;	
		}
		for(int i=0;i<w;++i){
			scanf("%d%d%d",&u,&v,&d);
			es[E].cost=-d;
			es[E].from=u;
			es[E++].to=v;
				
		}
		if(findloop())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

