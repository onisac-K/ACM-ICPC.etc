#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>L;X--)
#define DEP2(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

const int maxn=1e5+5;
const int mod=9973;
char a[maxn]; 
ll hash[maxn];

ll mod_reverse(ll a, ll m){
	ll y=0,x=1,r=a%m, q, t, mm=m;
	if(r<0)r=r+m;
	while((m%r) != 0) {
		a=m; m=r;
		q= a/m; r=a % m;
		t=x; x=y-x*q; y=t;
	}
	if(r!=1) return 0;
	if(x<0) x=x+mm;
	return x;
}

int main(){
	int q;
	while(~scanf("%d",&q))
	{
		getchar();
		gets(a+1);
		int n=strlen(a+1); 		
		REP(i,n+1) hash[i]=1;
		REP2(i,1,n){
			hash[i]=(hash[i-1]*(a[i]-28))%mod;
		}
	//	REP(i,n) cout<<hash[i]<<' ';cout<<endl; 
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			ll ans=(hash[r]*mod_reverse(hash[l-1],mod))%mod;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}
/*
2
ACMlove2015
1 11
8 10
1
testMessage
1 1
*/
