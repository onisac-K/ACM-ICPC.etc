#include<bits/stdc++.h>
using namespace std;
double a[3005],c[3005];
double sum[3005]; 
int main()
{
	int n;
	cin>>n;
	cin>>a[0]>>a[n+1];
	double s=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%lf",&c[i]);
		sum[i]=sum[i-1]+2*c[i];
		s+=sum[i];
	} 
	//cout<<s<<endl;
	double ans=a[n+1]+n*a[0]-s;
	ans/=(n+1);
	printf("%.2f",ans);
	return 0;
}
