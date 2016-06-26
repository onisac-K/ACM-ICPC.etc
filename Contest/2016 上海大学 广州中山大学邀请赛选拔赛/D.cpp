#include<bits/stdc++.h>
using namespace std;
#define ll long long

int vis[26];
char a[100005];

int main()
{
	int t;
	cin>>t;
	int f=1;
	
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%s",a);
		int lence=strlen(a);
		for(int i=0;i<lence;++i)vis[(a[i]-'a')]++;
		int ans=999999;
		for(int i=0;i<26;++i) ans=min(ans,vis[i]);
		printf("Case %d: ",f++);
		printf("%d\n",ans);
	}
	return 0;
}

/*
2
abcdefghijklmnopqrstuvwxy
efzadeuopqxrvwxaghijklmnbcastbqy
*/
