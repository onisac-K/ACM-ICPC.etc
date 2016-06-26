#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define VII vector<PII>
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
vector<pair<int,PII> > s;

int G[105][105];
int c[105];
int P[105];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		s.clear();
		int n,p,q;
		memset(G,0,sizeof(G));
		memset(c,0,sizeof(c));
		memset(P,0,sizeof(P));
		cin>>n>>p>>q;
		int x,y,v;
		for(int i=0;i<p;++i)
		{
			scanf("%d%d",&x,&v);
			x--;
			c[x]=v;
		}
		for(int i=0;i<q;++i)
		{
			scanf("%d%d%d",&x,&y,&v);
			x--;y--;
			G[x][y]=max(v,G[x][y]);
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(G[i][j])s.PB(MP(G[i][j],MP(i,j)));
			}
		}
		int k=min(n,q);
		for(int i=0;i<k;++i)
		{
			for(int j=0;j<s.size();++j)
			{
				int d=s[j].first;
				x=s[j].second.first;
				y=s[j].second.second;
				if(c[x]<(c[y]+d) && d>0)
				{
					P[x]=max(P[x],c[y]+d);
				}
			}
			for(int i=0;i<n;++i)if(P[i])c[i]=P[i];
			
		}
		
		cout<<c[0]<<endl;
	}
	return 0;
}

