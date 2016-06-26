#include <bits/stdc++.h>
#define lowbit(x) (x) & (-x)
using namespace std;
#define ll long long 
const int N = 1005;
const int M = 1e9 + 7;
 
ll dp[N][N], c[N][N];
ll a[N], r[N];
 
bool cmp(int b, int c) {
    return a[b] < a[c];
}
 
void update(int i, int j, int value)
{
    while(i < N) {
        c[i][j] = c[i][j] + value % M;
        i += lowbit(i);
    }
}
ll sum(int i, int j)
{
    ll s = 0;
    while(i > 0) {
        s = s + c[i][j] % M;
        i -= lowbit(i);
    }
    return s % M;
}

int main()
{
	int t;
	cin>>t;
	int f=1;
	while(t--)
	{
		int n,m;
		memset(c,0,sizeof(c));
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		for(int i=0;i<=n;++i)r[i]=i;
		sort(r+1,r+n+1,cmp);
		for(int i=1;i<=n;++i)
		{
			ll id=r[i];
			dp[id][1]=1;
			update(id,1,1);
			for(int j=2;j<=m;++j)
			{
				dp[id][j]=sum(id-1,j-1);
				update(id,j,dp[id][j]);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;++i)ans+=dp[i][m]%M;
		printf("Case #%d: %d\n",f++,ans%M);
	}
} 
