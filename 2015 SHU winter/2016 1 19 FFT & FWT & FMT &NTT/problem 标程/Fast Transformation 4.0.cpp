#include <bits/stdc++.h>
#define REP(X,N) for(int X=0;X<N;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
using namespace std;
 
#define MOD 1000000007
 
void Mod(int& a) {
    if(a >= MOD) a -= MOD;
    if(a < 0) a += MOD;
}
 
const int N = 16;
struct poly{
    int c[N];
    poly(){};
    poly& operator=(const poly& b) {
        REP(i,N) c[i] = b.c[i];
        return *this;
    }
    poly operator+(const poly& b) {
        poly res;
        REP(i,N) {
            Mod(res.c[i] = c[i] + b.c[i]);
        }
        return res;
    }
    poly operator-(const poly& b) {
        poly res;
        REP(i,N) {
            Mod(res.c[i] = c[i] - b.c[i]);
        }
        return res;
    }
    poly operator*(const poly& b) {
        poly res;
        res.clear();
        REP(i,N)
        REP(j,N-i)
            Mod(res.c[i+j] += 1LL*c[i]*b.c[j] % MOD);
        return res;
    }
    void clear() {
        REP(i,N) c[i] = 0;
    }
};
 
 
void fmt(poly * a, int n) {
    int m = __builtin_ctz(n)-1;
    REP(i,m) {
        REP(j,n) if(!(j>>i&1)) {
            a[j|(1<<i)] = a[j|(1<<i)] + a[j];
        }
    }
}
 
void ifmt(poly * a, int n) {
    int m = __builtin_ctz(n)-1;
    REP(i,m) {
        REP(j,n) if(!(j>>i&1)) {
            a[j|(1<<i)] = a[j|(1<<i)] - a[j];
        }
    }
}
 
poly a[1<<17], b[1<<17];
poly c[1<<17];
 
int main() {
#ifdef LOCAL
    freopen("1969.in", "r", stdin);
    freopen("1969.out", "w", stdout);
#endif
    int n;
    while(~scanf("%d",&n)) {
        int N = 1;
        while(N<=n) N*=2;
        REP(i,N) {
            a[i].clear();
            b[i].clear();
        }
        REP(i,n) scanf("%d", &a[i].c[__builtin_popcount(i)]);
        REP(i,n) scanf("%d", &b[i].c[__builtin_popcount(i)]);
         
         
        fmt(a, N);
        fmt(b, N);
         
        REP(i,N) c[i] = a[i] * b[i];
        ifmt(c, N);
        /* Brute Force
        REP(i,n) c[i] = 0;
        REP(i,n)
        REP(j,n) if(i & j == 0)
            c[i|j] += a[i] * b[j];
        */
        REP(i,n) {
            if(i) printf(" ");
            printf("%d", c[i].c[__builtin_popcount(i)]);
        }
        puts("");
    }
    return 0;
}
