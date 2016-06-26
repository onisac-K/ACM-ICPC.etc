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
#define MAXN 400005
#define lson(x) x*2
#define rson(x) x*2+1

int l[MAXN],r[MAXN];
ll b[MAXN],sum[MAXN];
//int a[MAXN];

void pushup(int x)
{
	sum[x]=sum[x<<1]+sum[x<<1|1];
} 

void build(int i,int L,int R)
{
	l[i]=L;
	r[i]=R;
	b[i]=0;
	if(R==L+1)
	{
		sum[i]=1;
		return ;
	}
	int mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid,R);
	pushup(i);
}



void pushdown(int x)
{
	if(b[x]==0)return ;
	//sum[x<<1]=sum[x<<1]*k[x]+(r[x<<1]-l[x<<1])
	int lson=x<<1;
	int rson=x<<1|1;
	sum[lson]=1LL*(r[lson]-l[lson])*b[x];
	b[lson]=b[x];
	sum[rson]=1LL*(r[rson]-l[rson])*b[x];
	b[rson]=b[x];
	b[x]=0;
}

void update(int i,int L,int R,int B)
{
	if(L==l[i]&&R==r[i])
	{
		sum[i]=1LL*(r[i]-l[i])*B;
		b[i]=B;
		return ;
	}
	pushdown(i);
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)update(i<<1,L,R,B);
	else if(L>=mid)update(i<<1|1,L,R,B);
	else 
	{
		update(i<<1,L,mid,B);
		update(i<<1|1,mid,R,B);
	}
	pushup(i);	
}

ll query(int i, int L,int R)
{
	if(L==l[i]&&R==r[i])return sum[i];
	pushdown(i);
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)return query(i<<1,L,R);
	else if(L>=mid)return query(i<<1|1,L,R);
	else return query(i<<1,L,mid)+query(i<<1|1,mid,R);
	pushup(i); 
}

int main()
{
	int t;
	cin>>t;
	int cnt=1;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		build(1,1,1+n);
		//cout<<query(1,1,11)<<endl;
		for(int i=1;i<=m;++i)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			update(1,a,b+1,c);
			//cout<<query(1,1,1+n)<<endl;
		}
		printf("Case %d: The total value of the hook is %d.\n",cnt++,query(1,1,n+1));
	} 
}


