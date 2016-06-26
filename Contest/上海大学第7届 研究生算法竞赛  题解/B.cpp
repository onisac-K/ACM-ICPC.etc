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

int a[100000];

int main()
{
#ifdef LOCAL
	   freopen("B.in","r",stdin);
	   freopen("B.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) {
        int n;
        cin>>n;
        REP(i,n) cin>>a[i];
        REP(i,n) a[i] -= i;
        sort(a, a+n);
        reverse(a, a+n);
        REP(i,n) a[i] += i;
        int f = 0;
        REP(i,n) {
            if(a[i] < 0 || i && a[i-1] < a[i]) {
                f = 1;
            }
        }
        if(f) {
            puts("Impossible");
            continue;
        }
        REP(i,n) {
            if(i) putchar(' ');
            printf("%d", a[i]);
        }
        puts("");
	}
	return 0;
}
