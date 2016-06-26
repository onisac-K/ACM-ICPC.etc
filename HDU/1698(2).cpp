#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
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
#define XINF INT_MAX
#define INF 0x3FFFFFFF
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
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

#define MAXN 100000*3
int c[MAXN];

void pushdown(int t) {
	if(c[t] != 0) {
		c[lson(t)] = c[rson(t)] = c[t];
		c[t] = 0;
	}
}

void update(int t, int L, int R, int l, int r, int x) {
	l = max(l, L);
	r = min(r, R);
	if(l > R || r < L) return ;
	if(l == L && r == R) {
		c[t] = x;
		return ;
	}
	pushdown(t);
	int M = (L+R)>>1;
	update(lson(t), L, M, l, r, x);
	update(rson(t), M+1, R, l, r, x);
}

int query(int t, int L, int R,int x){
	if(c[t])return c[t];
	int m=(L+R)>>1;
	if(x<=m)return query(2*t,L,m,x);
	else return query(2*t+1,m+1,R,x);
}

int main()
{
	int t, n, q, cs = 1;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &q);
		c[1] = 1;
		REP(i,q) {
			int x, y, z;
			scanf("%d%d%d",&x,&y,&z);
			x--; y--;
			update(1, 0, n-1, x, y, z);
		}
		int ans = 0;
		REP(i,n) {
			ans += query(1, 0, n-1,i);
		}
		printf("Case %d: The total value of the hook is %d.\n", cs++, ans);
	}
	
	return 0;
}

