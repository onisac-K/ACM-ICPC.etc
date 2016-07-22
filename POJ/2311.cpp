#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int sg[205][205];

int f(int n,int m){
	if(sg[n][m]!=-1)return sg[n][m];
	bool vis[205];
	memset(vis,false,sizeof(vis));
	for(int i=2;i<=n-i;++i)
		vis[f(n-i,m) ^ f(i,m)] = 1;		
	for(int i=2;i<=m-i;++i)
		vis[f(n,m-i) ^ f(n,i)] = 1;
	
	for(int i=0;;++i){
		if(!vis[i])return sg[n][m]=i;
	}
}

int main()
{
	int n,m;
	memset(sg,-1,sizeof(sg));
	while(cin>>n>>m){
		cout<<(f(n,m)==0? "LOSE":"WIN")<<endl;
	}
}
