#include<bits/stdc++.h>
using namespace std;

int G[105][105];
int grade[105];
vector<int> S[105];
int ans[105];

int update(int i){
	if(S[i].size() == 0)return ans[i] = grade[i];
	if(ans[i] != -1)return ans[i];
	int g = grade[i];
	for(int j=0;j<S[i].size();++j){
		if(g < G[i][S[i][j]]+update(S[i][j])){
			g = G[i][S[i][j]]+update(S[i][j]);
		}
	}
	return ans[i] = g; 
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(grade,0,sizeof(grade));
		memset(G,-1,sizeof(G));
		int n,p,q;
		cin>>n>>p>>q;
		for(int i=0;i<=n;++i)S[i].clear();
		int x,y,z;
		for(int i=0;i<p;++i){
			scanf("%d%d",&x,&y);
			grade[x] = max(grade[x],y);
		}
		for(int i=0;i<q;++i){
			scanf("%d%d%d",&x,&y,&z);
			G[x][y] = max(G[x][y],z);
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)
				if(G[i][j]>0)S[i].push_back(j);
		}
		memset(ans,-1,sizeof(ans));
		update(1);
		cout<<ans[1]<<endl;
	}
	return 0;
}
