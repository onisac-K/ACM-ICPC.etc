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
#define INF 0x3FFFFFFF;
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define CLR(A,X) memset(A,X,sizeof(A))
#define Rep(x,n) for(int x=0;x<n;++x)
#define Rep2(x,l,n) for(int x=l;x<n;++x)
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int MAXN = 100010;

int ra[1005],pa[1005];
int flag[1005];

void init(int n)
{
	for(int i=0;i<=n;++i)
	{
		ra[i]=0;
		pa[i]=i;
		flag[i]=0;
	}
}

int find(int x)
{
	if(x!=pa[x])pa[x]=find(pa[x]);
	return pa[x];
}

void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)return;
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
	x=find(x);
	y=find(y);
	if(x==y)return 1;
	else return 0;
}

int main()
{
	int n,m;
	ios::sync_with_stdio(0);
	while(cin>>n>>m)
	{
		init(n);
		VII v;
		v.PB(MP(0,0));
		for(int i=0;i<n;++i)
		{
			int x,y;
			cin>>x>>y;
			v.push_back(MP(x,y));
		}
	    char s;
	    int k1,k2;
	    while(cin>>s)
	    {
	    	if(s=='O')
	    	{
	    		cin>>k1;	    	
	    		flag[k1]=1;
	    		for(int i=1;i<=n;++i)
	    		{
	    			if(same(k1,i))continue;
	    			if(flag[i]==1 && i!=k1)
	    			{
	    				int dis=(v[i].first-v[k1].first)*(v[i].first-v[k1].first);
	    				dis+=(v[i].second-v[k1].second)*(v[i].second-v[k1].second);
						if(dis<=m*m)
	    				{
	    					unite(i,k1);
						}
					}
				}
			}
			else if(s=='S')
			{
				cin>>k1>>k2;
				if(same(k1,k2))cout<<"SUCCESS"<<endl;
				else cout<<"FAIL"<<endl;
			}
	    	//cout<<s<<' '<<k<<endl;
		}
	}

	return 0;
}
