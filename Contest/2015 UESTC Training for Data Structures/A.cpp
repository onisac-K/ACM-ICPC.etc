#include<bits/stdc++.h>
using namespace std; 

#define X first
#define Y second
#define MAXN 100005*8 
#define ll long long

ll num[MAXN]; 
ll l[MAXN],r[MAXN];
ll sum[MAXN];
ll k[MAXN];
map<ll,ll> ma;

void push_up(ll x)
{
	sum[x]=sum[x<<1]+sum[x<<1|1];
}


void debug()
{
	for(int i=0;i<10;++i)cout<<i<<' '<<l[i]<<' '<<r[i]<<' '<<k[i]<<' '<<sum[i]<<endl;
	cout<<endl;
}

void build(ll i,ll L,ll R)
{
	l[i]=L;r[i]=R;
	if(R==L+1)
	{
		sum[i]=0;
		return;
	}
	ll mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid,R);
	push_up(i);
}

void update_node(ll x,ll v)
{
	sum[x]=sum[x]+(r[x]-l[x])*v;
	k[x]+=v;
	
}

void push_down(ll x)
{
	update_node(x<<1,k[x]);
	update_node(x<<1|1,k[x]);
	k[x]=0;
}

void update(ll i,ll L,ll R,ll v)
{
	if(L==l[i] && R==r[i])
	{
		update_node(i,v);
		//k[i]+=v;
		return;
	}
	push_down(i);
	ll mid=(l[i]+r[i])>>1;
	if(R<=mid)
		update(i<<1,L,R,v);
	else if(L>=mid)
		update(i<<1|1,L,R,v);
	else
	{
		update(i<<1,L,mid,v);
		update(i<<1|1,mid,R,v);
	}
	push_up(i);
}

ll query(ll i,ll L,ll R)
{
	if(L==l[i] && R==r[i])
		return sum[i];
	push_down(i);
	ll mid=(l[i]+r[i])>>1;
	if(R<=mid)
		return query(i<<1,L,R);
	else if(L>=mid)
		return query(i<<1|1,L,R);
	else
		return query(i<<1,L,mid)+query(i<<1|1,mid,R);
	push_up(i);
}

struct node{
	int flag;
	ll l;
	ll r;
	ll v;
}T[MAXN];

int main()
{
	ll n,m;
	cin>>n>>m;
	ll qqq[4];
	int L=1;
	for(int i=0;i<m;++i)
	{
		scanf("%d",&T[i].flag);
		if(T[i].flag==0)
		{
			for(int j=0;j<3;++j)scanf("%lld",&qqq[j]);
			T[i].l=qqq[0];
			T[i].r=qqq[1];
			T[i].v=qqq[2];
			num[L++]=qqq[0];
			num[L++]=qqq[1];
		}
		else 
		{
			scanf("%lld",&T[i].v);
			T[i].l=0;
			T[i].r=0;
			num[L++]=T[i].v;
		}
	}
	//for(int i=1;i<L;++i)cout<<num[i]<<endl;
	sort(num+1,num+L);
	L = unique(num+1,num+L)-num;
	
	for(int i=1;i<L;++i)
	{
		ma[num[i]]=i;
	}
	//cout<<ma.size()<<endl;
	/*for(int i=1;i<L;++i)cout<<num[i]<<' '<<ma[num[i]]<<endl;
	cout<<endl; */
	int nn=ma.size();
	build(1,1,1+nn);
	//cout<<123<<endl;
	for(int i=0;i<m;++i)
	{
		//debug();
		//cout<<123<<endl;
		//cout<<T[i].l<<' '<<T[i].r<<' '<<T[i].v<<endl;	
		//cout<<ma[T[i].l]<<' '<<ma[T[i].r]<<' '<<T[i].v<<endl;
		if(T[i].flag==0)
			update(1,ma[T[i].l],ma[T[i].r]+1,T[i].v);
		else 
		{
			//cout<<123<<endl;
			printf("%lld\n",query(1,ma[T[i].v],ma[T[i].v]+1));
		}
	}
	
	return 0;
}
/*

10 5
0 1 3 1
1 2
0 1 5 1
1 2
1 5

*/
