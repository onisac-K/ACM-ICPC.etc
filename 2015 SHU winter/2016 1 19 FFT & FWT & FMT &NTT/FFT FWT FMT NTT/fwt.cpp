
const int M = 1000000007;
const int N = 1<<16;

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

//usage
/*
ll a[N], b[N];

mo = 1LL * M * N;
REP(i,N) a[i] = ..;
REP(i,N) b[i] = ..;
fwt(a,0,N-1);
fwt(b,0,N-1);
REP(i,N) a[i]=mul(a[i],b[i]);
ifwt(a,0,N-1);
REP(i,N) a[i] = (a[i]+mo)%mo/N;

*/
