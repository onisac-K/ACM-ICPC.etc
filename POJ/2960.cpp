#include<bits/stdc++.h>
using namespace std;

int s[105];
int f[10005];
int k;

int mex(int val){
	if(f[val]!=-1)return f[val];
	bool vis[10005];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<k;++i){
		int v = val - s[i];
		if(v>=0){
			f[v] = mex(v);
			vis[f[v]] = 1;
		}
		else break;
	}
	for(int i=0;;++i){
		if(vis[i] == false){
			return f[val]=i;
		}
	}
}

int main(){
	while(scanf("%d",&k) && k){
		memset(f,-1,sizeof(f));
		memset(s,0,sizeof(s));
		for(int i=0;i<k;++i)
			scanf("%d",&s[i]);
		sort(s,s+k);
		int n;
		scanf("%d",&n);
		while(n--){
			int m;
			cin>>m;
			int ans = 0;
			int num;
			while(m--){
				scanf("%d",&num);
				ans = ans ^ mex(num);
			}
			if(ans==0) printf("L");  
   			else printf("W"); 
		}
		cout<<endl;
	}
	return 0;
}
