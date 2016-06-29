#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MAXN 100000*4
#define ll long long
int l[MAXN],r[MAXN];
ll sum[MAXN];
int a[MAXN];

void push_up(int x)
{
	sum[x]=min(sum[x<<1],sum[x<<1|1]);
}

void build(int i,int L,int R)
{
	l[i]=L;r[i]=R;
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

ll query(int i,int L,int R)
{
	if(L==l[i] && R==r[i])
		return sum[i];
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		return query(i<<1,L,R);
	else if(L>=mid)
		return query(i<<1|1,L,R);
	else
		return min(query(i<<1,L,mid),query(i<<1|1,mid,R));
	push_up(i);
}

int main()
{
	int t,f=1;;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		build(1,1,n+1);
		printf("Case %d:\n",f++);
		int l,r;
		for(int i=0;i<q;++i)
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(1,l,r+1));
		}
	}
	return 0;
}
