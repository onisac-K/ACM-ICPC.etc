#include <cstdio>
#include <cstring>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define Lson l,m,lson
#define Rson m+1,r,rson
#define set(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int maxn = 100010;
ll k[maxn << 2], b[maxn << 2], sum[maxn << 2];
void PushUp(int rt) {
    sum[rt] = sum[lson] + sum[rson];
}
void PushDown(int rt, int m) {
    if (k[rt] == 1 && b[rt] == 0) return;
    k[lson] *= k[rt]; b[lson] = b[lson] * k[rt] + b[rt];
    k[rson] *= k[rt]; b[rson] = b[rson] * k[rt] + b[rt];
    sum[lson] = sum[lson] * k[rt] + b[rt] * (m - (m >> 1));
    sum[rson] = sum[rson] * k[rt] + b[rt] * (m >> 1);
    k[rt] = 1; b[rt] = 0;
}
void build(int l, int r, int rt) {
    k[rt] = 1; b[rt] = 0;
    if (l == r) {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    PushUp(rt);
}
void update(int L, int R, int kk, int bb, int l, int r, int rt) {
    if (L <= l && r <= R) {
        k[rt] *= kk; b[rt] = b[rt] * kk + bb;
        sum[rt] = sum[rt] * kk + bb * (r - l + 1);
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, kk, bb, Lson);
    if (m < R) update(L, R, kk, bb, Rson);
    PushUp(rt);
}
ll query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return sum[rt];
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    ll ret = 0;
    if (L <= m) ret += query(L, R, Lson);
    if (m < R) ret += query(L, R, Rson);
    return ret;
}

int main() {
#ifdef MANGOGAO
    // freopen("data.in", "r", stdin);
    freopen("/Users/Lodour/Downloads/0.in", "r", stdin);
    freopen("/Users/Lodour/Downloads/my0.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        set(k, 0); set(sum, 0);
        build(1, n, 1);
        while (m--) {
            int op;
            scanf("%d", &op);
            if (op == 1) {
                int x, y, kk, bb;
                scanf("%d%d%d%d", &x, &y, &kk, &bb);
                update(x, y, kk, bb, 1, n, 1);
            }
            else {
                int x, y;
                scanf("%d%d", &x, &y);
                printf("%lld\n", query(x, y, 1, n, 1));
            }
        }
    }
    return 0;
}
