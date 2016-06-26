#include<bits/stdc++.h>
using namespace std;

struct node
{
	int l,r,n;
}a[400005];

int init(int l,int r,int i)
{
	a[i].l=l;
	a[i].r=r;
	a[i].n=1;
	if(l!=r)
	{
		int mid=(l+r)>>1;
		init(l,mid,2*i);
		init(mid+1,r,2*i+1);
	}
}

void update(int i,int l,int r,int v)
{
	if(a[i].n==v)return ;
	if(a[i].l==l && a[i].r==r)
	{
		a[i].n=v;
		return ;
	}
	if(a[i].n!=-1)
	{
		a[2*i].n=a[2*i+1].n=a[i].n;
		a[i].n=-1;
	}
	int mid=(a[i].l+a[i].r)>>1;
	if(l>mid)
	{
		update(2*i+1,l,r,v);
	}
	else if(r<=mid)
	{
		update(2*i,l,r,v);
	}
	else 
	{
		update(2*i,l,mid,v);
		update(2*i+1,mid+1,r,v);
	}	
}

int s(int i)
{
	if(a[i].n!=-1)return (a[i].r-a[i].l+1)*a[i].n;
	else 
	return s(2*i)+s(2*i+1);
}

int main()
{
	int t;
	cin>>t;
	int cas=1;
	while(t--)
	{
		int n,m;
		int a,b,c;
		scanf("%d%d",&n,&m);
		init(1,n,1);
		for(int i=0;i<m;++i)
		{		
			scanf("%d%d%d",&a,&b,&c);
			update(1,a,b,c);
		}
		printf("Case %d: The total value of the hook is %d.\n",cas++,s(1));
	}
	return 0;
}
