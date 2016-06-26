#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005*4
#define ll long long
int l[MAXN],r[MAXN];
ll k[MAXN],b[MAXN],sum[MAXN];
ll a[MAXN];

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
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	build(1,1,n+1);
	int m;
	cin>>m;
	ll l,r,v;
	for(int i=0;i<m;++i)
	{
		scanf("%lld%lld%lld",&l,&r,&v);
		update(1,l,r+1,1,v);
		printf("%lld\n",query(1,l,r+1));
	}
	return 0;
}


