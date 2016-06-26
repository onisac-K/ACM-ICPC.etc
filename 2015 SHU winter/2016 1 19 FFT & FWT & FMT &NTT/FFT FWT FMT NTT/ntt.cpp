/*
    P     N
998244353 3
1004535809 3
786433 10
880803841 26

*/

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
