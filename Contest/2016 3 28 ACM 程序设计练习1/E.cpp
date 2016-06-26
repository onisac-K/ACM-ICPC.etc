#include<bits/stdc++.h>
using namespace std;
#define ll long long
  
ll a[25];
int n,k;
set<ll> s;
int vis[25];
int ans=0;
  
bool ispri(ll x)
{
    ll k=sqrt(x);
    for(int i=2;i<=k;++i)
    {
        if(x%i==0)return 0;
    }
    return 1;
}
  
void dfs(ll x,int num)
{
    if(num==k)
    {
        ll kk=0;
        for(int i=0;i<n;++i)
        {
            kk=kk*2+vis[i];
        }
        if(!s.count(kk))
        {
             
            s.insert(kk);
            if(ispri(x))
            {
                ans++;
                //cout<<x<<endl;
            }
        }
        return ;
    }
    if(num>k)return ;
    for(int i=0;i<n;++i)
    {
        if(vis[i]==1)continue;
        else
        {
            vis[i]=1;
            dfs(a[i]+x,num+1);
            vis[i]=0;
        }
    }
}
  
int main()
{
    while(cin>>n>>k)
    {
        ans=0;
        s.clear();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;++i)scanf("%d",&a[i]);
        for(int i=0;i<n;++i)
        {
            vis[i]=1;
            dfs(a[i],1);
        }
        cout<<ans<<endl;
    }
}
