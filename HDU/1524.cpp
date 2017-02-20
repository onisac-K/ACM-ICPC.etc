#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;


vector<int> G[1005]; 
int sg[10005];

int mex(int val){
	if(sg[val]!=-1)return sg[val];
	bool vis[10005];
	memset(vis,false,sizeof(vis));
	//cout<<val<<' '<<G[val].size()<<endl;
	for(int i=0;i<G[val].size();++i){
		vis[mex(G[val][i])] = 1;
	}
	for(int i=0;;++i){
		if(vis[i] == false){
			return sg[val]=i;
		}
	}
}

int main()
{	
	int n;
	while(cin>>n){
		memset(sg,-1,sizeof sg);
		int m,v;
		for(int i=0;i<n;++i){
			G[i].clear();
			scanf("%d",&m);
			for(int j=0;j<m;++j){
				scanf("%d",&v);
				G[i].push_back(v);	
			}
		}
		int k;
		while(cin>>k && k){
			int ans = 0;
			for(int i=0;i<k;++i){
				scanf("%d",&v);
				ans ^= mex(v);
			}
			if(ans)cout<<"WIN"<<endl;
			else cout<<"LOSE"<<endl;
		}
	}
	return 0;
}
