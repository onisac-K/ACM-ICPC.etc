#include <bits/stdc++.h>
#define REP(X,N) for(int X=0;X<N;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
using namespace std;
typedef long long ll;
 
const int N = 1 << 18;  
const int P = (479 << 21) + 1;  
const int G = 3;  
ll wn[31];
 
ll pow_mod(ll a, ll b, ll m) {
    ll res = 1, t = a%m;
    while(b) {
        if(b&1) res = res*t%m;
        b>>=1;
        t = t*t%m;
    }
    return res;
}
 
void GetWn() {
    REP(i, 31) {  
        int t = 1 << i;  
        wn[i] = pow_mod(G, (P - 1) / t, P);  
    }
}
 
void Rader(ll a[], int len) {
    int j = len >> 1;
    for(int i=1; i<len-1; i++) {
        if(i < j) swap(a[i], a[j]);
        int k = len >> 1;
        while(j >= k) {
            j -= k;
            k >>= 1;
        }
        if(j < k) j += k;
    }
}
   
void NTT(ll a[], int len, int on) {
    Rader(a, len);
    for(int h = 2, id = 0; h <= len; h <<= 1) {
        id++;
        for(int j = 0; j < len; j += h) {
            ll w = 1;
            for(int k = j; k < j + h / 2; k++) {
                ll u = a[k] % P;
                ll t = w * (a[k + h / 2] % P) % P;  
                a[k] = (u + t) % P;
                a[k + h / 2] = ((u - t) % P + P) % P;  
                w = w * wn[id] % P;
            }
        }
    }
    if(on == -1) {
        for(int i = 1; i < len / 2; i++)  
            swap(a[i], a[len - i]); 
        ll Inv = pow_mod(len, P - 2, P);
        REP(i,len)
            a[i] = a[i] % P * Inv % P;  
    }
}
 
 
ll a[1<<18], b[1<<18];
ll c[1<<18];
 
int main() {
#ifdef LOCAL
    freopen("1966.in", "r", stdin);
    freopen("1966.out", "w", stdout);
#endif
    GetWn();
    int n;
    while(~scanf("%d",&n)) {
        REP(i,n) scanf("%lld", &a[i]);
        REP(i,n) scanf("%lld", &b[i]);
         
        int N = 1;
        while(N<n) N*=2;
        N*=2;
         
        REP(i, N) if(i>=n) a[i] = b[i] = 0;
         
        NTT(a, N, 1);
        NTT(b, N, 1);
         
        REP(i, N) c[i] = 1LL*a[i]*b[i]%P;
        NTT(c, N, -1);
        /* Brute Force
        REP(i,n) c[i] = 0;
        REP(i,n)
        REP(j,n)
            c[i+j] += a[i] * b[j];
        */
        REP(i,n) {
            if(i) printf(" ");
            printf("%d", (int)c[i]);
        }
        puts("");
    }
    return 0;
}
