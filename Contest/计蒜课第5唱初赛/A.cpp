#include<bits/stdc++.h>

using namespace std; 
double a[105];
double pi = 3.1415926535898;
double L,c;
int n,m;

double get(double l)
{
	double s = l/2;
	//cout<<cos(c)<<endl;
	double q = s*s*2-2*s*s*cos(c);
	//cout<<q<<' '<<123<<endl;
	return sqrt(q);
}

int main()
{

	cin>>n>>m;
	cin>>L;
	a[0]=L;
	c = 180.0-360.0/n;
	//cout<<c<<endl;
	c = c/180*pi;
	for(int i=1;i<=m;++i)
	{
		a[i]=get(a[i-1]);
	}
	double ans = 0;
	//cout<<a[1]<<endl;
	for(int i=0;i<m;++i)ans+=(a[i]*(n-0.5));
	ans+=a[m]*(n-1);
	printf("%.6f",ans);
	return 0;
 } 
