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

#define MAXN 100010

int H;

int bit[MAXN];
int sum(int i) {
    i++;
    int r = 0;
    while(i) {
        r += bit[i];
        i -= i&-i;
    }
    return r;
}

void add(int i, int x) {
    i++;
    while(i<MAXN) {
        bit[i] += x;
        i += i&-i;
    }
}

int l[MAXN], r[MAXN], x[MAXN];
int id[MAXN];
int id1[MAXN], id2[MAXN];
int ans[MAXN];
int tmp[MAXN];

void solve(int head, int tail, int L, int R) {
    //cout<<head<<' '<<tail<<' '<<L<<' '<<R<<endl;
    if(head > tail) return ; 
    if(L == R) {
        for(int i = head; i <= tail; i++) ans[id[i]] = L;
        return ;
    }
    int M = (L+R)>>1;
    int l1 = 0, l2 = 0;
    for(int i = L; i <= M; i++) {
        add(l[i], x[i]);
        add(r[i]+1, -x[i]);
    }
    for(int i = head; i <= tail; i++) {
        if(tmp[id[i]] + sum(id[i]) >= H) {
            id1[l1++] = id[i];
        }else{
            tmp[id[i]] += sum(id[i]);
            id2[l2++] = id[i];
        }
    }
    for(int i = L; i <= M; i++) {
        add(l[i], -x[i]);
        add(r[i]+1, x[i]);
    }
    REP(i,l1) id[head+i] = id1[i];
    REP(i,l2) id[head+l1+i] = id2[i];
    solve(head, head+l1-1, L, M);
    solve(head+l1, tail, M+1, R);
}

int main()
{
#ifdef LOCAL
        freopen("H.in","r",stdin);
        freopen("H.out","w",stdout);
#endif
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,m;
        scanf("%d%d%d", &n, &m, &H);
        REP(i,m) {
            scanf("%d%d%d",&l[i],&r[i],&x[i]);
            l[i]--; r[i]--;
        }
        //l[m] = 0;
        //r[m] = n-1;
        //x[m] = INF;
        REP(i,n) {
            id[i] = i;
            tmp[i] = 0;
            ans[i] = -1;
        }
        solve(0, n-1, 0, m);
        
        VII vec;
        REP(i,n) {
            //cout<<ans[i]<< ' '<<i<<endl;
            if(ans[i] != m) vec.PB(MP(ans[i], i));
        }
        sort(ALL(vec));
        assert(vec.size() > 0);
        printf("%d\n", vec.size());
        REP(i,vec.size()) {
            if(i) printf(" ");
            printf("%d", vec[i].Y+1);
        }
        puts("");
    }
    return 0;
}
