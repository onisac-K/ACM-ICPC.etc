#include<bits/stdc++.h>
using namespace std;
#define maxn 200000*4
int m[maxn],l[maxn],r[maxn];
int a[maxn];

void build(int i,int L,int R)
{
	l[i]=L;
	r[i]=R;
	if(R==L)
	{
		m[i]=a[L];
		return ;
	}
	int mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid+1,R);
	m[i]=max(m[i<<1],m[i<<1|1]);
}

void update(int i,int pos,int x,int L,int R)
{
	//cout<<i<<','<<pos<<','<<x<<','<<L<<','<<R<<endl;;
	if(R==L)
	{
		m[i]=x;	
		return ;
	}
	int mid=(L+R)>>1;
	if(pos<=mid)update(i<<1,pos,x,L,mid);
	else if(pos>mid)update(i<<1|1,pos,x,mid+1,R);
	m[i]=max(m[i<<1],m[i<<1|1]);	
}

int query(int i,int L,int R)
{
	cout<<i<<' '<<l[i]<<' '<<r[i]<<endl;
	if(r[i]==R && l[i]==L)return m[i];
	int mid=(r[i]+l[i])/2;
	if(mid>=R)return query(i<<1,L,R);
	else if(mid<=L)return query(i<<1|1,L,R);
	else return max(query(i<<1,L,mid),query(i<<1|1,mid+1,R));
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		build(1,1,n);
		char x[2];
		for(int i=0;i<m;++i)
		{
			scanf("%s",x);
			int a,b;
			scanf("%d%d",&a,&b);
			if(x[0]=='Q')
			{	
				cout<<query(1,a,b)<<endl;
			}
			else 
			{							
				update(1,a,b,1,n);
			}
		}
	}
	return 0;
}

