#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
pair<double,double> a[105];
pair<double,double> b[105];

int main()
{
	int n,m;
	scanf("%d",&n);
	double x,y;
	for(int i=0;i<n;++i)
	{
		scanf("%lf%lf",&x,&y);
		if(i>0&&x<a[i-1].second)x=a[i-1].second;
		a[i].first=x;
		a[i].second=y;
	}
	scanf("%d",&m);
	double ans=0;
	for(int i=0;i<m;++i)
	{
		scanf("%lf%lf",&x,&y);
		for(int j=0;j<n;++j)
		{
			if(a[j].X>=x&&a[j].Y<=y)ans+=(a[j].Y-a[j].X);
			else if(a[j].X<x&&a[j].Y<=y&&a[j].Y-x>0)ans+=(a[j].Y-x);
			else if(a[j].X>=x&&a[j].Y>y&&y-a[j].X>0)ans+=(y-a[j].X);
			else if(a[j].X<x&&a[j].Y>y)ans+=(y-x);
		}
		//cout<<ans<<endl;
	}
	printf("%.3f\n",ans);
	return 0;
} 
