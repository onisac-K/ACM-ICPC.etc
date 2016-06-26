#include <bits/stdc++.h>
#define REP(X,N) for(int X=0;X<N;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
using namespace std;
 
#define MOD 1000000007
 
void Mod(int& a) {
    if(a >= MOD) a -= MOD;
    if(a < 0) a += MOD;
}
 
void fmt(int* a, int n) {
    int m = __builtin_ctz(n)-1;
    REP(i,m) {
        REP(j,n) if(!(j>>i&1)) {
            Mod(a[j|(1<<i)] += a[j]);
        }
    }
}
 
void ifmt(int* a, int n) {
    int m = __builtin_ctz(n)-1;
    REP(i,m) {
        REP(j,n) if(!(j>>i&1)) {
            Mod(a[j|(1<<i)] -= a[j]);
        }
    }
}
 
int a[1<<17], b[1<<17];
int c[1<<17];
 
int main() {
#ifdef LOCAL
    freopen("1968.in", "r", stdin);
    freopen("1968.out", "w", stdout);
#endif
    int n;
    while(~scanf("%d",&n)) {
        REP(i,n) scanf("%d", &a[i]);
        REP(i,n) scanf("%d", &b[i]);
         
        int N = 1;
        while(N<=n) N*=2;
         
        REP(i,N) if(i>=n) a[i] = b[i] = 0;
         
        fmt(a, N);
        fmt(b, N);
         
        REP(i,N) c[i] = 1LL * a[i] * b[i] % MOD;
        ifmt(c, N);
        /* Brute Force
        REP(i,n) c[i] = 0;
        REP(i,n)
        REP(j,n)
            c[i|j] += a[i] * b[j];
        */
        REP(i,n) {
            if(i) printf(" ");
            printf("%d", c[i]);
        }
        puts("");
    }
    return 0;
}
