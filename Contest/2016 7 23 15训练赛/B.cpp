#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int G_real[105][105],G_may[105][105];
vector<int> path[105][105];

void init(int n){
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			path[i][j].clear();
			G_real[i][j] = INF;
			G_may[i][j] = INF;	
		}
		
	}
}

int getreal(int s,int t){
	if(path[s][t].size() == 0)return G_real[s][t];
	int ans = INF;
	for(int i=0;i<path[s][t].size();++i){
		ans = min(ans,getreal(s,path[s][t][i])+getreal(path[s][t][i],t));
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,s,e;
		cin>>n>>m>>s>>e;
		init(n);
		int u,v,a,b;
		for(int i=0;i<m;++i){
			scanf("%d%d%d%d",&u,&v,&a,&b);
			G_real[u][v] = G_real[v][u] = b;
			G_may[u][v] = G_may[v][u] = a;
		}
	
	    for(int k=1;k<=n;k++){
	        for(int i=1;i<=n;i++){
	            for(int j=1;j<=n;j++){
	                if(G_may[i][k] + G_may[k][j] < G_may[i][j]){
	                	G_may[i][j] = G_may[i][k] + G_may[k][j];
	                	path[i][j].clear();
	                	path[i][j].push_back(k);
					}
					else if(G_may[i][k] + G_may[k][j] == G_may[i][j]){
						path[i][j].push_back(k);
					}
	            }}}
	    cout<<G_may[s][e]<<' ';
	    cout<<getreal(s,e)<<endl;
	}
	return 0;
}
