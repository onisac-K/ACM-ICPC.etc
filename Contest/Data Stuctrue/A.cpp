#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXN 100005*4
#define X first
#define Y second
int l[MAXN],r[MAXN];
int sum[MAXN];
int a[MAXN];
int K[MAXN];

void build(int i,int L,int R)
{
	K[i]=0;
	l[i]=L;r[i]=R;
	if(R==L+1)
	{
		sum[i]=a[L];
		return;
	}
	int mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid,R);
}

void update_node(int x,int y)
{
	if(y==1)sum[x]*=-1;
	K[x]+=y;
	K[x]%=2;
}

void push_down(int x)
{
	update_node(x<<1,K[x]);
	update_node(x<<1|1,K[x]);
	K[x]=0;
}

void update(int i,int L,int R)
{
	if(L==l[i] && R==r[i])
	{
		update_node(i,1);
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
}

int query(int i,int L,int R)
{
	if(L==l[i] && R==r[i])
		return sum[i];
	push_down(i);
	int mid=(l[i]+r[i])>>1;
	if(R<=mid)
		return query(i<<1,L,R);
	else if(L>=mid)
		return query(i<<1|1,L,R);
}

void debug()
{
	for(int i=1;i<=10;++i)cout<<query(1,i,1+i)<<' ';cout<<endl;
}

char s[100000];

int main()
{
	int t;
	cin>>t;
	int f=1;
	while(t--)
	{
		scanf("%s",&s);
		int L = strlen(s);
		for(int i=0;i<L;++i)
		{
			if(s[i]=='0')a[i+1]=-1;
			else a[i+1]=1;
		}
		build(1,1,1+L);
		int q;
		cin>>q;
		printf("Case %d:\n",f++);
		while(q--)
		{
			//debug();
			char p[2];
			int l,r;
			scanf("%s",p);
			if(p[0]=='I')
			{
				scanf("%d%d",&l,&r);
				update(1,l,r+1);
			}
			else if(p[0]=='Q')
			{
				scanf("%d",&l);
				int x = query(1,l,l+1);
				if(x==-1)x=0;
				printf("%d\n",x);
			}
		}
	}
	return 0;
}
/*
2
0011001100
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5
1011110111
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5*/
