#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	double x;
	for(int i=-100;i<=100;++i)
	{
		for(int j=0;j<100;++j)
		{
			x=i+j*1.0/100;
			if(fabs(a*x*x*x+b*x*x+c*x+d)<=0.0001)printf("%.2f ",x);
		}
	}
} 
