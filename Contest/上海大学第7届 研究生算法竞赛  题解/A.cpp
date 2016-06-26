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

int dir[4][2] = {0,1,0,-1,1,0,-1,0};
char a[100][101];
int dp[100][100][21];

int main()
{
#ifdef LOCAL
       freopen("A.in","r",stdin);
       freopen("A.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    int t,si,sj;
    cin>>t;
    while(t--) {
        int n,m,s,c;
        cin>>n>>m>>s>>c;
        REP(i,n) {
            cin>>a[i];
            REP(j,m) {
                if(a[i][j] == 'S') {
                    si = i;
                    sj = j;
                }
            }
        }
        int ans = INF;
        CLR(dp, 0x3f);
        dp[si][sj][s] = 0;
        queue<pair<PII, int> > q;
        q.push(MP(MP(si,sj), s));
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            int x = p.X.X;
            int y = p.X.Y;
            int ss = p.Y;
            if(a[x][y] == 'T') {
                ans = min(ans, dp[x][y][ss]);
            }
            int ts = min(ss+1, s);
            if(dp[x][y][ts] > dp[x][y][ss] + 1) {
                dp[x][y][ts] = dp[x][y][ss] + 1;
                q.push(MP(MP(x,y),ts));
            }
            REP(i,4) {
                int tx = x + dir[i][0];
                int ty = y + dir[i][1];
                if(tx >= 0 && ty >= 0 && tx < n && ty < m) {
                    if(a[tx][ty] == '.' || a[tx][ty] == 'T') {
                        ts = min(ss+1, s);
                        if(dp[tx][ty][ts] > dp[x][y][ss] + 1) {
                            dp[tx][ty][ts] = dp[x][y][ss] + 1;
                            q.push(MP(MP(tx,ty),ts));
                        }
                    }
                    if(a[tx][ty] == 'D') {
                        ts = ss - c + 1;
                        if(ss >= c && dp[tx][ty][ts] > dp[x][y][ss] + 2) {
                            dp[tx][ty][ts] = dp[x][y][ss] + 2;
                            q.push(MP(MP(tx,ty),ts));
                        }
                    }
                }
            }
        }
        cout<<(ans == INF ? -1 : ans)<<endl;
    }
    return 0;
}
