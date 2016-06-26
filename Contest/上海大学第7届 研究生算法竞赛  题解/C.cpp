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

int c1[10] = {0}, c2[10] = {0};
PII test(int a, int b) {
    int x = 0, y = 0;
    CLR(c1,0);
    CLR(c2,0);
    REP(i,5) {
        if(a % 10 == b % 10)
            x++;
        c1[a % 10] ++;
        c2[b % 10] ++;
        a /= 10;
        b /= 10;
    }
    REP(i,10) {
        y += min(c1[i], c2[i]);
    }
    return MP(x,y);
}

int a[100];
int x[100];
int y[100];

int main()
{
#ifdef LOCAL
	   freopen("C.in","r",stdin);
	   freopen("C.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) {
        int n;
        cin>>n;
        REP(i,n) {
            cin>>a[i];
            cin>>x[i]>>y[i];
        }
        int ans = 0;
        REP(i,100000) {
            int cx = 0, cy = 0;
            int f = 0;
            REP(j,n) {
                PII p = test(i, a[j]);
                if(p.X != x[j] || p.Y != y[j]) {
                    f = 1;
                }
            }
            if(!f) ans++;
        }
        cout<<ans<<endl;
	}
	return 0;
}
