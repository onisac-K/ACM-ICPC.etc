#include<bits/stdc++.h>
using namespace std;

int a[105];

struct node
{
	int x;
	int y;
	friend bool operator<(node a,node b)
	{
		return a.x<b.x;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		queue<node>q;
		priority_queue<node>qq;
		int xx;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&xx);
			node a;
			a.x=xx;
			if(i!=m)
			{
				a.y=0;
				q.push(a);
			}
			else 
			{
				a.y=1;
				q.push(a);
			}
			a.y=0;
			qq.push(a);
		}
		int ans=0;
		while(!q.empty())
		{
			node x=q.front();
			node y=qq.top();
			if(x.x==y.x)
			{
				if(x.y==1)break;
				ans++;
				q.pop();
				qq.pop();
			}
			else 
			{
				q.pop();
				q.push(x);
			}
		}
		cout<<ans+1<<endl;
	}
}
