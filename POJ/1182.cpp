#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm> 
using namespace std;
int pa[160010],ra[160010];

int init(int n)
{
	for(int i=0;i<=n;++i)
	{
		pa[i]=i;
		ra[i]=0;
	}
}

int find(int x)
{
	if(x==pa[x])return x;
	else return pa[x]=find(pa[x]);
}

void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)return ;
	if(ra[x]>ra[y])
	{
		pa[y]=x;
	}
	else
	{
		pa[x]=y;
		if(ra[x]==ra[y])ra[y]++;
	}
	return ;
}

bool same(int x,int y)
{
	if(find(x)==find(y))return 1;
	return 0;
}

int main()
{
	int n,k;
	cin>>n>>k;
	init(n*3);
	int ans=0;
	for(int i=0;i<k;++i)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(x>n||y>n||x<0||y<0)
		{
			ans++;
			continue;
		}
		x--;
		y--;
		
		if(t==1)
		{
			if(same(x,y+n)||same(x,y+2*n))
			{
				ans++;
				continue;
			}
			else 
			{
				unite(x,y);
				unite(x+n,y+n);
				unite(x+2*n,y+2*n);
			}
		}
		else 
		{
			if(same(x,y)||same(x,y+2*n))
			{
				ans++;
				continue;
			}
			else 
			{
				unite(x,y+n);
				unite(x+n,y+2*n);
				unite(x+2*n,y);
			}
		}
	}
	cout<<ans<<endl;
}
