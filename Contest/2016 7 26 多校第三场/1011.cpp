#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
int vis[100005*2];
int main()
{
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		int n,m;
		ll aa,bb;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i){
			scanf("%lld%lld",&aa,&bb);
			a[i] = aa*100000+bb;
		}
		int flag = 0;
		sort(a,a+n);
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				int x = a[j]/100000 - a[i]/100000;
				int y = a[j]%100000 - a[i]%100000;
				if(x<0)x*=-1;
				if(y<0)y*=-1;
				if(x+y==0)continue;
				if(vis[x+y]==0){
					vis[x+y]=1;
				}
				else {
					flag = 1;
					break;
				}
			}
		}
		if(flag == 1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
