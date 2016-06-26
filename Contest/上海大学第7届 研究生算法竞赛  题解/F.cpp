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

int fa[200000];

int init(int n) {
    REP(i,n) fa[i] = -1;
}

int find(int x) {
    return fa[x] == -1 ? x : fa[x] = find(fa[x]);
}

int unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    fa[x] = y;
    return 1;
}

vector<PII> v[17];
int tmp[200000];

int main()
{
#ifdef LOCAL
	   freopen("F.in","r",stdin);
	   freopen("F.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	while(T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        init(n*2);
        REP(i,17) v[i].clear();
        REP(i,m) {
            int l, r;
            scanf("%d%d",&l,&r); l--; r--;
            int len = r-l+1;
            int k = 0;
            while((1<<k)*2 < len) k++;
            v[k].PB(MP(l,r+n));
            v[k].PB(MP(r-(1<<k)+1,l+n-1+(1<<k)));
        }
        DEP(k,16,0) {
            REP(j,v[k].size()) {
                PII p = v[k][j];
                unite(p.X, p.Y);
            }
            if(k) {
                int len = 1<<(k-1);
                REP(i,n*2) {
                    tmp[i] = find(i);
                    if(tmp[i] == i) tmp[i] = -1;
                    else if(tmp[i] >= n) tmp[i] -= len;
                    else tmp[i] += len;
                }
                REP(i,n) {
                    if(tmp[i] != -1) unite(i+len, tmp[i]);
                    if(tmp[i+n] != -1) unite(i+n-len, tmp[i+n]);
                }
            }
        }
        REP(i,n) unite(i, i+n);
        int ans = 0;
        REP(i,n*2) {
            if(find(i) == i) ans++;
        }
        printf("%d\n", ans);
	}
	return 0;
}
