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
