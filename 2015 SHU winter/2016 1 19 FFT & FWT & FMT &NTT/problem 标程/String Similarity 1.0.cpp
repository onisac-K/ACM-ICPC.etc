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
 
const double pi=acos(-1.0);
typedef complex<double> Complex;
  
void build(Complex _P[], Complex P[], int n, int m, int curr, int &cnt) {
    if(m==n) {
        _P[curr]=P[cnt++];
    }else{
        build(_P,P,n,m*2,curr,cnt);
        build(_P,P,n,m*2,curr+m,cnt);
    }
}
void FFT(Complex P[], int n ,int oper) {
    static Complex _P[1<<19];
    int cnt=0;
    build(_P,P,n,1,0,cnt);
    copy(_P,_P+n,P);
    for(int d=0;(1<<d)<n;d++) {
        int m=1<<d;
        int m2=m*2;
        double p0=pi/m*oper;
        Complex unit_p0=Complex(cos(p0), sin(p0));
        for(int i=0;i<n;i+=m2) {
            Complex unit=1;
            for(int j=0;j<m;j++) {
                Complex &P1=P[i+j+m], &P2=P[i+j];
                Complex t=unit*P1;
                P1=P2-t;
                P2=P2+t;
                unit=unit*unit_p0;
            }
        }
    }
}
 
char S[100010];
char T[100010];
 
Complex p1[1<<19], p2[1<<19];
int sum1[1<<19], sum2[1<<19];
 
 
int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    while(~scanf("%s%s",S,T)) {
        // define a = 1, b = 0
        // C = (a-b)^2 = a^2 + b^2 - 2*a*b;
        // use FFT to calc a*b ,
        // use prefix sum to calc a^2 && b^2 
        int a=strlen(S);
        int b=strlen(T);
        //printf("%d,%d,",a,b);
        //if(strstr(S,T)==NULL) printf(".");
        reverse(T,T+b);
        int N = 1;
        while(N <= a+b) N*=2;
        REP(i,N) p1[i]=i<a?Complex(S[i]-'a'):Complex(0);
        REP(i,N) p2[i]=i<b?Complex(T[i]-'a'):Complex(0);
        FFT(p1,N,1);
        FFT(p2,N,1);
        REP(i,N) p1[i]*=p2[i];
        FFT(p1,N,-1);
        REP(i,N) p1[i]/=Complex(N,0);
         
        int ans=INF;
        REP(i,a) sum1[i+1]=sum1[i]+S[i]-'a';
        REP(i,b) sum2[i+1]=sum2[i]+T[i]-'a';
        REP(i,a-b+1) {
            //S[i, i+b-1] * T^(-1)[0,b-1] -> (a*b)[i, i+b-1]
            int ab = (int)(p1[i+b-1].real()+0.5);
            int a2 = sum1[i+b]-sum1[i];
            int b2 = sum2[b];
            int C = a2 + b2 - 2*ab; // a^2 + b^2 - 2*a*b
            ans=min(ans,C);
        }
        printf("%d\n",ans);
    }
    return 0;
}
