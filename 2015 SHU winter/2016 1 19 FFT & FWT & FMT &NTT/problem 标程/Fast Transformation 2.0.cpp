#include <bits/stdc++.h>
#define REP(X,N) for(int X=0;X<N;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
using namespace std;
typedef long long ll;
 
const int M = 1000000007;
 
ll mo;
ll mul(ll a,ll b){
    return ((a*b-ll(((long double)a)/mo*b+1e-3)*mo)%mo+mo)%mo;
}
ll pow_mod(ll a, ll n) {
    a%=mo;
    ll r = 1;
    while(n) {
        if(n&1) r = mul(r,a);
        a=mul(a,a);
        n>>=1;
    }
    return r;
}
void fwt(ll *a,int l,int r){
    if(l!=r){ 
        int mid=l+r>>1,len=mid-l+1;
        fwt(a,l,mid);
        fwt(a,mid+1,r);             
        for (int i=l;i<=mid;i++){
            ll u=a[i],v=a[i+len];
            a[i]=(u+v)%mo;
            a[i+len]=(u-v)%mo;
        }
    }
} 
void ifwt(ll *a,int l,int r){
    if(l!=r){              
        int mid=l+r>>1,len=mid-l+1;
        for (int i=l;i<=mid;i++){
            ll u=a[i],v=a[i+len];
            a[i]=(u+v)%mo;
            a[i+len]=(u-v)%mo;
        }
        ifwt(a,l,mid);
        ifwt(a,mid+1,r);
    }
} 
 
ll a[1<<17], b[1<<17];
ll c[1<<17];
 
int main() {
#ifdef LOCAL
    freopen("1967.in", "r", stdin);
    freopen("1967.out", "w", stdout);
#endif
    int n;
    while(~scanf("%d",&n)) {
        REP(i,n) scanf("%lld", &a[i]);
        REP(i,n) scanf("%lld", &b[i]);
         
        int N = 1;
        while(N<n) N*=2;
         
        mo = 1LL * M * N;
        REP(i,N) if(i>=n) a[i] = b[i] = 0;
         
        fwt(a, 0, N-1);
        fwt(b, 0, N-1);
         
        REP(i,N) c[i] = mul(a[i], b[i]);
        ifwt(c, 0, N-1);
        REP(i,N) c[i] = (c[i]+mo)%mo/N;
        /* Brute Force
        REP(i,n) c[i] = 0;
        REP(i,n)
        REP(j,n)
            c[i^j] += a[i] * b[j];
        */
        REP(i,n) {
            if(i) printf(" ");
            printf("%d", (int)c[i]);
        }
        puts("");
    }
    return 0;
}
