#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 100100
using namespace std;
typedef long long ll;
int n,tot;
ll m;
char a[2][M],ans[M<<1];
int main()
{
     
    //freopen("coin.in","r",stdin);
    //freopen("coin.out","w",stdout);
     
    int i,x;
    ll j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        scanf("%d",&x),a[0][i]=x-1;
    for(j=2;j<=m;j<<=1)
        if(m&j)
        {
            ++tot;
            for(i=1;i<=n;i++)
            {
                int x=(i+(j>>1)%n+n-1)%n+1;
                int y=(i-(j>>1)%n+n-1)%n+1;
                a[tot&1][i]=a[~tot&1][x]^a[~tot&1][y];
            }
        }
    for(i=1;i<=n;i++)
        ans[i+i-1]=a[tot&1][i];
    if(m&1)
    {
        for(i=1;i<=n;i++)
            ans[i<<1]=ans[i+i-1]^ans[i==n?1:i<<1|1];
        for(i=1;i<=n;i++)
            ans[i+i-1]=-1;
    }
    else
    {
        for(i=1;i<=n;i++)
            ans[i+i]=-1;
    }
    for(i=1;i<=n<<1;i++)
        printf("%d%c",ans[i]+1,i==n+n?'\n':' ');
         
}
