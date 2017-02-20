#include<bits/stdc++.h>
using namespace std;

int G[26][26];
int vis[26];

bool bfs()
{
	queue<int>q;
	q.push('b'-'a');
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		int t = q.front();
		vis[t] = 1;
		q.pop();
		if(t == 'm'-'a')return true;
		for(int i=0;i<26;++i){
			if(vis[i]==0 && G[t][i]==1)
				q.push(i);
		}
	}
	return false;
}

int main()
{
	char str[105];
	while(cin>>str){
		if(str[0] != '0'){
			int L = strlen(str);
			G[str[0]-'a'][str[L-1]-'a']=1;
		}
		else if(str[0] == '0'){
			cout<<(bfs()? "Yes.":"No.")<<endl;
			memset(G,0,sizeof(G));
		}
	}
	return 0;
} 
