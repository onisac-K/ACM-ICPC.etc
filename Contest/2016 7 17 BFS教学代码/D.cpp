#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

int vis[200005];

int main()
{
	int s,t;
	while(cin>>s>>t)
	{
		memset(vis,0,sizeof(vis));
		queue<int>q;
		q.push(s);
		vis[s] = 1;
		while(!q.empty()){
			int x = q.front();
			q.pop();
			if(x<0 || x>=100005)continue;
			if(x == t)break;
			if(x+1<=t && vis[x+1] == 0){
				q.push(x+1);
				vis[x+1] = vis[x]+1;
			}
			if(x>=1 && vis[x-1] == 0){
				q.push(x-1);
				vis[x-1] = vis[x]+1;
			}
			if(x<t && vis[x*2] == 0){
				q.push(x*2);
				vis[x*2] = vis[x]+1;
			}
		}
		cout<<vis[t]-1<<endl;
	}

	return 0;
}
