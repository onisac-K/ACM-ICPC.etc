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
ll sum0[MAXN];
ll num[MAXN];

ll gcd(ll a,ll b)
{
	return (b==0)? a:gcd(b,a%b);
 } 

void push_up(int x)
{
	sum0[x]=gcd(sum0[x<<1],sum0[x<<1|1]);
}

void build(int i,int L,int R)
{
	l[i]=L;r[i]=R;
	if(R==L+1)
	{
		//cout<<i<<endl;
		sum0[i]=num[L];
		return;
	} 
	int mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid,R);
	push_up(i);
}



ll query(int i,int L,int R)
{
	if(L==l[i] && R==r[i])		
	{
	//	cout<<l[i]<<' '<<r[i]<<endl;
	//	cout<<sum0[i]<<" "<<sum1[i]<<" "<<sum2[i]<<" "<<a[i]<<endl;
		return sum0[i];
	}
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		return query(i<<1,L,R);
	else if(L>=mid)
		return query(i<<1|1,L,R);
	else
		return gcd(query(i<<1,L,mid),query(i<<1|1,mid,R));
}

int main()
{
	int n,q;
	while(cin>>n>>q)
	{
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	for(int i=1;i<=n;++i)scanf("%d",&num[i]);
	build(1,1,n+1);
	//for(int i=0;i<16;++i)cout<<i<<' '<<l[i]<<' '<<r[i]<<' '<<sum0[i]<<endl;
	int c,d;
	for(int i=0;i<q;++i)
	{
		scanf("%d%d",&c,&d);
		printf("%d\n",query(1,c,d+1));
	}
	
	}
	return 0;
}

/*
4 4
1 1 1 1
1 2
2 3
3 4
4 4
*/
