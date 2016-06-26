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
#define ll long long
#define MAXN 100005
#define lson(x) x*2
#define rson(x) x*2+1
ll c[3*MAXN],sum[3*MAXN];
ll a[MAXN];
void pushdown(int i,int L, int R)
{
	if(c[i]==0)return ;
	int M=(L+R)>>1;
	c[lson(i)]+=c[i];
	c[rson(i)]+=c[i];
	sum[lson(i)]+=c[i]*(M-L+1);//2?¨º? c[lson(i)]
	sum[rson(i)]+=c[i]*(R-M);
	c[i]=0;
}

void pushup(int i)
{
	sum[i]=sum[2*i]+sum[2*i+1];
}

void build(int i,int L, int R)
{
	c[i]=0;
	if(L==R)
	{
		sum[i]=a[L];
		return ;
	}
	int M=(L+R)>>1;
	build(2*i,L,M);
	build(2*i+1,M+1,R);
	pushup(i);	
}

void update(int i,int L,int R,int l,int r,int x)
{
	l=max(l,L);
	r=min(r,R);
	if(l>R || r<L)return ;
	if(l==L && r==R)
	{
		c[i]+=x;
		sum[i]+=1LL*x*(R-L+1);
		return ;
	}
	pushdown(i,L,R);
	int M=(L+R)>>1;
	update(2*i,L,M,l,r,x);
	update(2*i+1,M+1,R,l,r,x);
	pushup(i);
}

ll query(int i,int L,int R,int l,int r)
{
	l=max(l,L);
	r=min(r,R);
	if(l>R || r<L)return 0;
	if(l==L && r==R)
	{
		return sum[i];
	}
	pushdown(i,L,R);
	int M=(L+R)>>1;
	ll res = query(2*i,L,M,l,r)+query(2*i+1,M+1,R,l,r);
	pushup(i);
	return res;
}

int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	build(1,1,n);
	char s[2];
	for(int i=0;i<q;++i)
	{
		scanf("%s",s);
		if(s[0]=='Q')
		{
			int a,b;
			scanf("%d%d",&a,&b);
			cout<<query(1,1,n,a,b)<<endl;	
		}
		else if(s[0]=='C')
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			update(1,1,n,a,b,c);
		}
	}
	return 0;
}
