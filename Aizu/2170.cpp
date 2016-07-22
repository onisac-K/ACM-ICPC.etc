#include<bits/stdc++.h>
using namespace std;
#define ll long long

int par[100005];
int vis[100005];
int n,q;

int find(int x){
	while(par[x]!=x && vis[x]!=1){
		x = par[x];
	}
	return x;
}

int main()
{
	while(cin>>n>>q && (n||q)){
		for(int i=2;i<=n;++i){
			scanf("%d",&par[i]);
		}
		memset(vis,0,sizeof(vis));
		vis[1]=1;
		char s[2];int x;
		ll sum = 0;
		for(int i=0;i<q;++i){
			scanf("%s %d",s,&x);
			if(s[0]=='M')vis[x]=1;
			else {
				sum += find(x);
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

