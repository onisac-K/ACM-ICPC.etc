#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		//vector<pair<int,int> >v;
		int x,y;
		int mix=99999,miy=99999;
		int maxx=-99999,mayy=-99999;
		
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			mix=min(mix,x);
			miy=min(miy,y);
			maxx=max(maxx,x);
			mayy=max(mayy,y);
		}
		x=maxx-mix;
		y=mayy-miy;
		x=max(x,y);
		printf("%d\n",x*x);
	}
	return 0;
} 
