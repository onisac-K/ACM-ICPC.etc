#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

pair<int,int> s[5005];
int a[5005];
int vis[5005];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int x,y;
		for(int i=0;i<n;++i){
			scanf("%d%d",&x,&y);
			s[i] = make_pair(x,y);
		}
		sort(s,s+n);
		for(int i=0;i<n;++i){
			a[i] = s[i].second;
		}
		int cnt = 0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i){
			//cout<<a[i]<<endl;
			int st = a[i];
			if(vis[i])continue;
			vis[i] = 1;
			for(int j=i+1;j<n;++j){
				if(vis[j] == 1)continue;
				if(a[j]>=st){
					st = a[j];
					vis[j] = 1;
				}
			}
			cnt++;
		}
		
		cout<<cnt<<endl;
	}
	return 0;
}

