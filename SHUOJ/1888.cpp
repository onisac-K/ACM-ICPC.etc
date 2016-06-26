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
ll k[MAXN],b[MAXN],sum[MAXN];
int a[MAXN];

void pushup(int x)
{
	sum[x]=sum[x<<1]+sum[x<<1|1];
} 

void build(int i,int L,int R)
{
	l[i]=L;
	r[i]=R;
	k[i]=1;
	b[i]=0;
	if(R==L+1)
	{
		sum[i]=a[L];
		return ;
	}
	int mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid,R);
	pushup(i);
}



void pushdown(int x)
{
	//sum[x<<1]=sum[x<<1]*k[x]+(r[x<<1]-l[x<<1])
	int lson=x<<1;
	int rson=x<<1|1;
	sum[lson]=sum[lson]*k[x]+1LL*(r[lson]-l[lson])*b[x];
	k[lson]=k[lson]*k[x];
	b[lson]=k[x]*b[lson]+b[x];
	sum[rson]=sum[rson]*k[x]+1LL*(r[rson]-l[rson])*b[x];
	k[rson]=k[rson]*k[x];
	b[rson]=k[x]*b[rson]+b[x];
	k[x]=1;
	b[x]=0;
}

void update(int i,int L,int R,int K,int B)
{
	if(L==l[i]&&R==r[i])
	{
		sum[i]=sum[i]*K+1LL*(r[i]-l[i])*B;
		k[i]=k[i]*K;
		b[i]=b[i]*K+B;
		return ;
	}
	pushdown(i);
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)update(i<<1,L,R,K,B);
	else if(L>=mid)update(i<<1|1,L,R,K,B);
	else 
	{
		update(i<<1,L,mid,K,B);
		update(i<<1|1,mid,R,K,B);
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
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,1,n+1);
	while(q--)
	{
		int s;
		scanf("%d",&s);
		int a,b,c,d;
		if(s==1)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			update(1,a,b+1,c,d);
		}
		else 
		{
			scanf("%d%d",&a,&b);
			printf("%lld\n",query(1,a,b+1));
		}
	}
}

/*ll c[4*MAXN],b[4*MAXN],sum[4*MAXN];
ll a[MAXN];
void pushdown(int i,int L, int R)
{
    if(c[i]==0&&b[i]==1)return ;
    int M=(L+R)>>1;
    c[lson(i)]+=b[i]*c[lson(i)]+c[i];
    c[rson(i)]+=c[rson(i)]*b[i]+c[i];
    b[lson(i)]*=b[i];
    b[rson(i)]*=b[i];
    sum[lson(i)]=sum[lson(i)]*b[i]+c[i]*(M-L+1);
    sum[rson(i)]=sum[rson(i)]*b[i]+c[i]*(R-M);
    c[i]=0;
    b[i]=1;
}
 
void pushup(int i)
{
    sum[i]=sum[2*i]+sum[2*i+1];
}
 
void build(int i,int L, int R)
{
    c[i]=0;
    b[i]=1;
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
 
void update(int i,int L,int R,int l,int r,int x,int y)
{
    //cout<<123<<endl;
    l=max(l,L);
    r=min(r,R);
    if(l>R || r<L)return ;
    if(l==L && r==R)
    {
    //  cout<<123<<endl;
        c[i]=b[i]*y+x;
        b[i]*=y;
        sum[i]=1LL*sum[i]*y+1LL*x*(R-L+1);
        //pushdown(i,L,R);
        return ;
    }
    //cout<<123<<endl;
    pushdown(i,L,R);
    int M=(L+R)>>1;
    if(L<=M)update(2*i,L,M,l,r,x,y);
    if(R>M)update(2*i+1,M+1,R,l,r,x,y);
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
    ll res=0;
    if (L <= M) res += query(2*i,L,M,l,r);
    if (M < R) res += query(2*i+1,M+1,R,l,r);
    //ll res = query(2*i,L,M,l,r)+query(2*i+1,M+1,R,l,r);
    pushup(i);
    return res;
}
 
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    build(1,1,n);
    //cout<<123<<endl;
    int s;
    for(int i=0;i<q;++i)
    {
        scanf("%d",&s);
        //cout<<s<<endl;
        if(s==2)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(1,1,n,a,b));
            //cout<<query(1,1,n,a,b)<<endl; 
        }
        else
        {
            //cout<<123<<endl;
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            update(1,1,n,a,b,d,c);
            //for(int i=1;i<=15;++i)cout<<sum[i]<<endl;
            //cout<<query(1,1,n,1,5)<<endl;
        }
    }
    return 0;
}*/
