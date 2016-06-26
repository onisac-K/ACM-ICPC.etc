#include<bits/stdc++.h>
using namespace std;

struct point
{
	double x;
	double y;
}a[105];

double lence(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	int n;
	double r;
	cin>>n>>r;
	point a;
	point b;
	cin>>b.x>>b.y;
	point c;
	c.x=b.x,c.y=b.y;
	double ans=3.141592654*2*r;
	for(int i=1;i<n;++i)
	{
		cin>>a.x>>a.y;
		ans+=lence(a,b);
		b.x=a.x;
		b.y=a.y;
	}
	ans+=lence(b,c);
	printf("%.2f\n",ans);
	return 0;
}
