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
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)
 
ll v[100010];
unsigned int ans[100010];
int len;
 
char s[100010];
int main() {
    while(~scanf("%s", s)) {
        int l = strlen(s);
        len = 0;
        ll x = 0;
        REP(i,l) {
            x = x * 10 + s[i] - '0';
            if((l-i-1) % 9 == 0) {
                v[len++] = x;
                x = 0;
            }
        }
        reverse(v, v+len);
        int cnt = 0;
        do {
            ll c = 0;
            DEP(i,len-1,0) {
                v[i] += 1000000000ll * c;
                c = v[i] & (~0u);
                v[i] >>= 32;
            }
            ans[cnt++] = c;
            while(len > 1 && v[len-1] == 0) len--;
        }while(len > 1 || v[len-1] != 0);
        int f = 0;
        DEP(i, cnt-1, 0) {
            DEP(j, 31, 0) {
                int x = ans[i] >> j & 1;
                if(x != 0 || i + j == 0) f = 1;
                if(f) putchar('0' + x);
            }
        }
        puts("");
    }
    return 0;
}
