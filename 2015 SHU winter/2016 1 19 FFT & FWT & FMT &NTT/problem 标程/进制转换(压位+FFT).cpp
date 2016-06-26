//²Î¿¼×ÊÁÏ
//http://picks.logdown.com/posts/208342-positional-notation-conversion
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
 
const int N = 1 << 18;  
const int P = (479 << 21) + 1;  //1004535809
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
 
// LIMIT = 10^5 * logD(10) * D * D < P
ll _a[1<<20];
ll _b[1<<20];
struct BigBin{
    const int BITS = 8; // MIN = 4, MAX = 7 or 8
    const int D = 1<<BITS;
    int* num;
    int len;
    BigBin(unsigned short n = 0) {
        len = 1;
        num = new int[1];
        num[0] = n;
    }
    BigBin(const BigBin& b) {
        len = b.len;
        num = new int[len];
        REP(i,len) num[i] = b.num[i];
    }
    BigBin(int* a, int n) {
        len = n;
        num = new int[len];
        REP(i,len) num[i] = a[i];
    }
    BigBin(ll* a, int n) {
        len = n;
        num = new int[len];
        REP(i,len) num[i] = a[i];
    }
    ~BigBin() {
        delete[] num;
    }
    BigBin& operator=(const BigBin& b) {
        delete[] num;
        len = b.len;
        num = new int[len];
        REP(i,len) num[i] = b.num[i];
        return *this;
    }
    BigBin operator*(const BigBin& b) {
        int N = 1;
        while(N<=len+b.len+1) N*=2;
        REP(i,N) _a[i] = i<len?num[i]:0;
        REP(i,N) _b[i] = i<b.len?b.num[i]:0;
        NTT(_a,N,1);
        NTT(_b,N,1);
        REP(i,N) _a[i] = 1LL*_a[i]*_b[i]%P;
        NTT(_a,N,-1);
        ll c = 0;
        int l = 1;
        REP(i,N) {
            _a[i] += c;
            if(_a[i]) l = i+1;
            c = _a[i] / D;
            _a[i] %= D;
        }
        return BigBin(_a, l);
    }
    BigBin operator+(const BigBin& b) {
        int l = max(len, b.len);
        int c = 0;
        REP(i,l+1) {
            _a[i] = c;
            _a[i] += i<len?num[i]:0;
            _a[i] += i<b.len?b.num[i]:0;
            c = _a[i] / D;
            _a[i] %= D;
        }
        if(_a[l]) l++;
        return BigBin(_a, l);
    }
    void out() {
        int nz = 0;
        DEP(i,len-1,0) {
            DEP(j,BITS-1,0) {
                int x = num[i]>>j&1;
                if(x || i+j==0) nz = 1;
                if(nz) putchar('0'+x);
            }
        }
        putchar('\n');
    }
};
 
 
BigBin A[18];
 
char s[200000];
 
int num[1<<18];
 
BigBin solve(int *a, int L, int R) {
    if(L==R) return BigBin(a[L]);
    int M = (L+R)>>1;
     
    int len = R-L+1;
    int t = __builtin_ctz(len)-1;
     
    return solve(a, L, M) + solve(a, M+1, R) * A[t];
}
 
 
int main()
{
#ifdef LOCAL
    freopen("1970.in","r",stdin);
    freopen("1970.out","w",stdout);
#endif
    GetWn();
    A[0] = BigBin(10);
    //A[0].out();
    REP(i,17) {
        //A[i].out();
        A[i+1] = A[i] * A[i];
    }
    while(~scanf("%s", s)) {
        int n = strlen(s);
        REP(i,n) s[i] -= '0';
        reverse(s, s+n);
        int N = 1;
        while(N<=n) N*=2;
        REP(i,N) {
            num[i] = i<n?s[i]:0;
        }
        BigBin ans = solve(num, 0, N-1);
        ans.out();
    }
    return 0;
}
