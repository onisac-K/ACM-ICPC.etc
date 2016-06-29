#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
	int a;
	int b;
}num[1005];

struct node2
{
	int va;
	int i;
};

struct cmp
{
	bool operator()(node2 a,node2 b)
	{
		return a.va<b.va;
	}
};

int vis[1005];


int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int x;
		int sum=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&x);
			sum+=x;
			num[i].a=x;
		}
		for(int i=0;i<n;++i)
		{
			scanf("%d",&x);
			num[i].b=x;
		}
		priority_queue< node2,vector<node2>,cmp > q; 
		for(int i=0;i<n;++i)
		{
			for(int j=1;j<=num[i].a;++j)
			{
				node2 s;
				s.i=i;
				s.va=(j*j-(j-1)*(j-1))*num[i].b;
				q.push(s);
			}
		}
		//memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i)vis[i]=num[i].a;
		while(sum>m)
		{
			node2 s=q.top();
			q.pop();
			if(vis[s.i]>0)vis[s.i]--;
			else continue;
			sum--;
		}
		ll ans = 0;
		for(int i=0;i<n;++i)
		{
			ans += vis[i]*vis[i]*num[i].b;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
