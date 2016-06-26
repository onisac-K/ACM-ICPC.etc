#include <iostream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define XINF INT_MAX
#define INF 0x3f3f3f3f
#define MAXN 4*100010
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define sqr(a) ((a)*(a))
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define PF(X) push_front(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define PI  acos(-1.0)
#define test puts("OK");
#define lowbit(X) (X&(-X))
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef pair<int,int> PII;
typedef priority_queue<int,vector<int>,greater<int> > PQI;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second

int l[MAXN],r[MAXN];
ll k[MAXN],b[MAXN],sum[MAXN];
int a[MAXN];

void push_up(int x)
{
	sum[x]=sum[x<<1]+sum[x<<1|1];
}

void build(int i,int L,int R)
{
	l[i]=L;r[i]=R;
	k[i]=1;b[i]=0;
	if(R==L+1)
	{
		sum[i]=a[L];
		return;
	}
	int mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid,R);
	push_up(i);
}

void update_node(int x,int K,int B)
{
	sum[x]=sum[x]*K+1LL*(r[x]-l[x])*B;
	k[x]=k[x]*K;
	b[x]=b[x]*K+B;
}

void push_down(int x)
{
	update_node(x<<1,k[x],b[x]);
	update_node(x<<1|1,k[x],b[x]);
	k[x]=1;b[x]=0;
}

void update(int i,int L,int R,int K,int B)
{
	if(L==l[i] && R==r[i])
	{
		update_node(i,K,B);
		return;
	}
	push_down(i);
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		update(i<<1,L,R,K,B);
	else if(L>=mid)
		update(i<<1|1,L,R,K,B);
	else
	{
		update(i<<1,L,mid,K,B);
		update(i<<1|1,mid,R,K,B);
	}
	push_up(i);
}

ll query(int i,int L,int R)
{
	if(L==l[i] && R==r[i])
		return sum[i];
	push_down(i);
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		return query(i<<1,L,R);
	else if(L>=mid)
		return query(i<<1|1,L,R);
	else
		return query(i<<1,L,mid)+query(i<<1|1,mid,R);
	push_up(i);
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n+1);
	while(q--)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			update(1,a,b+1,c,d);
		}
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%lld\n",query(1,a,b+1));
		}
	}
	return 0;
}
