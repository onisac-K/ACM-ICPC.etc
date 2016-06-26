#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

int w[50], t[50], c[50];
int id[50];
int dp[101][51];

int cmp(int a, int b) {
    return t[a] > t[b];
}

void chmin(int &a, int b) {
    if(a > b) a = b;
}

int main()
{
#ifdef LOCAL
	   freopen("D.in","r",stdin);
	   freopen("D.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	int T,n,m,s;
	cin>>T;
	while(T--) {
        cin>>n>>m>>s;
        REP(i,m) {
            cin>>w[i]>>t[i]>>c[i];
            id[i] = i;
        }
        sort(id, id+m, cmp);
        CLR(dp,0x3f);
        dp[0][n] = 0;
        REP(d,m) {
            int i = id[d];
            REP2(j,1,min(t[i], n)) {
                REP(k,s+1-w[i]) {
                    chmin(dp[k+w[i]][j-1], dp[k][j] + c[i]);
                }
            }
        }
        for(int j=n;j>=0;--j)
		{
 			for(int i=0;i<10;++i)cout<<dp[i][j]<<' ';
			cout<<endl;
		}
        int ans = INF;
        REP(i,s+1) ans = min(ans, dp[i][0]);
        cout<<(ans == INF ? -1 : ans)<<endl;
	}
	return 0;
}
