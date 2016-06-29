#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int n,m;
int edge[100005]; 

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int u,v,k;
        memset(edge,INF,sizeof(edge));
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&u,&v,&k);
            if(v==u+1)edge[u]=min(edge[u],k);
        }
        long long ans = 0;
        int flag = 0;
        for(int i=1;i<=n-1;++i)
        {
        	if(edge[i]!=INF)ans += edge[i];
			else flag =1; 
		}
		if(flag == 1)cout<<-1<<endl;
		else cout<<ans<<endl;
    }
    return 0;
}
