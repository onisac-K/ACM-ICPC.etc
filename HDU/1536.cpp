#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
int s[105];
int sg[10005];
int k;

int mex(int val){
	if(sg[val]!=-1)return sg[val];
	bool vis[10005];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<k;++i){
		if(val-s[i]>=0){
			vis[mex(val-s[i])] = 1;
		}
		else break;
	}
	for(int i=0;;++i){
		if(vis[i] == false){
			return sg[val]=i;
		}
	}
}

int a[1000005];

int main()
{
	while(cin>>k && k) {
		memset(sg,-1,sizeof(sg));
		sg[0] = 0;		
		for(int i=0;i<k;++i)scanf("%d",&s[i]);
		sort(s,s+k);
		int t;cin>>t;
		while(t--){
		
			int n,ans = 0,x;
			cin>>n;
			for(int i=0;i<n;++i){
				scanf("%d",&x);
				ans ^= mex(x);
			}
			if(ans == 0)printf("L");
			else printf("W");
		}
		cout<<endl;
	}	
	return 0;
}
