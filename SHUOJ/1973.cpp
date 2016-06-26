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
ll sum0[MAXN],sum1[MAXN],sum2[MAXN];
ll a[MAXN];

void push_up(int x)
{
	sum0[x]=sum0[x<<1]+sum0[x<<1|1];
	sum1[x]=sum1[x<<1]+sum1[x<<1|1];
	sum2[x]=sum2[x<<1]+sum2[x<<1|1];
}

void build(int i,int L,int R)
{
	l[i]=L;r[i]=R;
	if(R==L+1)
	{
		sum0[i]=1;
		sum1[i]=0;
		sum2[i]=0;
		a[i]=0;
		return;
	} 
	int mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid,R);
	push_up(i);
}

void update_node(int x,int f)
{
	if((f)%3==1)
	{
		int a0=sum0[x],a1=sum1[x],a2=sum2[x];
		sum0[x]=a2;
		sum1[x]=a0;
		sum2[x]=a1;	
		a[x]+=f;
	}
	else if((f)%3==2)
	{
		int a0=sum0[x],a1=sum1[x],a2=sum2[x];
		sum0[x]=a1;
		sum1[x]=a2;
		sum2[x]=a0;	
		a[x]+=f;
	}
}

void push_down(int x)
{
	//cout<<x<<' '<<a[x]<<endl;
	update_node(x<<1,a[x]);
	update_node(x<<1|1,a[x]);
	a[x]=0;
}

void update(int i,int L,int R)
{
	if(L==l[i] && R==r[i])
	{
		//cout<<i<<endl;
		a[i]++;
		int x=i;
		int a0=sum0[x],a1=sum1[x],a2=sum2[x];
		sum0[x]=a2;
		sum1[x]=a0;
		sum2[x]=a1;	
		
		return;
	}
	push_down(i);
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		update(i<<1,L,R);
	else if(L>=mid)
		update(i<<1|1,L,R);
	else 
	{
		update(i<<1,L,mid);
		update(i<<1|1,mid,R);
	}
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
	cin>>n>>q;
	build(1,1,n+1);
	
	int f,aa,b;
	for(int i=0;i<q;++i)
	{
		scanf("%d%d%d",&f,&aa,&b);
		if(f==1)
		{
			printf("%lld\n",query(1,aa,b+1));
			//cout<<":"<<endl;
			//for(int i=1;i<=2*n-1;++i)cout<<sum0[i]<<" "<<sum1[i]<<" "<<sum2[i]<<' '<<l[i]<<' '<<r[i]<<endl;
		}
		if(f==0)
		{
			update(1,aa,b+1);
			//cout<<":"<<endl;
			//for(int i=1;i<=2*n-1;++i)cout<<sum0[i]<<" "<<sum1[i]<<" "<<sum2[i]<<' '<<a[i]<<' '<<l[i]<<' '<<r[i]<<endl;
		}
	} 
	return 0;
}
