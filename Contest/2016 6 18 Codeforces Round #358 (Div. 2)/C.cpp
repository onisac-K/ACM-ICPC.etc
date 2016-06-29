#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
vector<pair<int,int> >E[maxn];
int a[maxn];
int dfs(int x,long long dis)
{
    if(dis>a[x])return 0;
    long long ans = 1;
    for(int i=0;i<E[x].size();i++)
    {
        ans+=dfs(E[x][i].first,max(dis+E[x][i].second,0LL));
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int p,c;
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&p,&c);
        E[p].push_back(make_pair(i+1,c));
    }
    int ans = dfs(1,0);
    cout<<n-ans<<endl;
}
