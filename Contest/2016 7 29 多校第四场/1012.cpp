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
#define lowbit(i) (i&(-i))
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

int a[maxn],b[maxn],pos[maxn],pre[maxn],loc[maxn];
ll bit[maxn];
	
void add(int i,ll x)
{
	while(i<=maxn)
	{
		bit[i]+=x;
		i+=lowbit(i);
	}
}

ll query(int i)
{
	ll s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=lowbit(i);
	}
	return s;
}

int main(){
	int t,ca=1;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		REP2(i,1,n) scanf("%d",&a[i]);
		REP2(i,1,n) b[i]=a[i];
		sort(b+1,b+1+n);
		CLR(bit,0);
		CLR(pre,0);
		CLR(loc,0);
		REP2(i,1,n){
			pre[a[i]]=loc[a[i]]=i;
			int num=query(a[i]);
			
		//	cout<<query(a[i])<<endl;
			pre[a[i]]=min(pre[a[i]],num+1);
			add(a[i],1);
			
		}
		REP2(i,1,n)
			loc[b[i]]=max(loc[b[i]],i);
		printf("Case #%d:",ca++);
		REP2(i,1,n){
			printf(" %d",abs(pre[i]-loc[i]));	
		}
		puts("");
	}
	
	
	return 0;
}
/*
2
3
3 1 2
3
1 2 3
*/

