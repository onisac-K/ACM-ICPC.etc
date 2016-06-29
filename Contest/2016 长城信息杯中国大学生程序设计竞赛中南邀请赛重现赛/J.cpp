#include<bits/stdc++.h>
using namespace std;

vector<int> v[200000];
struct node{
	int k;
	int i;
}p[100004];
int q[100004];
int n;

void add(int i)
{
	for(int j=0;j<v[i].size();++j)
	{
		q[v[i][j]]+=p[i].k;
	}
}

void sub(int i,int vv)
{
	for(int j=0;j<v[i].size();++j)
	{
		q[v[i][j]]-=vv;
	}
}

bool cmp(node a,node b)
{
	if(a.k==b.k)return a.i<b.i;
	else return a.k<b.k;
}

int main()
{
	while(cin>>n)
	{
		memset(q,0,sizeof(q));
		for(int i=0;i<n;++i)
		{
			v[i].clear();
			scanf("%d",&p[i].k);
			p[i].i=i;
		}
		int u,vv;
		for(int i=0;i<n-1;++i)
		{
			scanf("%d%d",&u,&vv);
			u--;
			vv--;
			v[u].push_back(vv);
			v[vv].push_back(u);
		}
		for(int i=0;i<n;++i)
			add(i);
		sort(p,p+n,cmp);
		int ans = 0;
		for(int i=n-1;i>=0;--i)
		{
			ans += q[p[i].i];
			//cout<<ans<<endl;
			sub(p[i].i,p[i].k);
		}
		cout<<ans<<endl;
	}
}
