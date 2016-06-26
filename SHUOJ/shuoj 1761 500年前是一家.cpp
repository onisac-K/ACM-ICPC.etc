/*poj 1330*/

#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;

int pa[10005],root[10005];
vector<int> edge[10005];
int s,e;

void init(int n)
{
	memset(root,0,sizeof(root));

	for(int i=0;i<=n;++i)pa[i]=i;
	for(int i=0;i<=n;++i)edge[i].clear();
}

int find(int x)
{
	return pa[x]==x? x:(pa[x]=find(pa[x]));
}

void unite(int x ,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)return ;
	pa[x]=y;
}

bool same(int x, int y)
{
	if(find(x)==find(y))return 1;
	return 0;
}

int flag=0;
int ans=0;
  
int lca(int ro)
{
	int i,sz;
	
	sz=edge[ro].size();
	for(int i=0;i<sz;++i)
	{
		//cout<<ro<<' '<<edge[ro][i]<<endl;
		lca(edge[ro][i]);
		unite(edge[ro][i],ro);
	}
	/*for(int i=2;i<=9;++i)
	{
		if(same(i,1))cout<<i<<endl;
		
	}*/
	if(same(s,e))
	{
		if(flag==0)
		{
			ans=find(s);
			flag=1;
		}
		return find(s);
	}
	return 0;
}

int main()
{
	int t;
	cin>>t;
	int f=1;
	while(t--)
	{
		int n,m=1;
		
		cin>>n;
		init(n);
		int x,y;
		for(int i=0;i<n-1;++i)
		{
			scanf("%d%d",&x,&y);
			edge[x].push_back(y);
			root[y]++;
		}
		int ro=0;
		for(int i=1;i<=n;++i)if(root[i]==0)
		{
			ro=i;
			break;
		}
		//cout<<ro<<endl;
		//int m;
		//cin>>m;
		//printf("Case %d:\n",f++);
		for(int i=1;i<=1;++i)
		{
			for(int j=0;j<=n;++j)pa[j]=j;
			ans=0;
			flag=0;		
			scanf("%d%d",&s,&e);
			lca(ro);
		
			if(i==m)cout<<ans<<endl;
			else cout<<ans<<' ';
		}	
	}
	return 0;
} 
