#include<bits/stdc++.h>
using namespace std;
int sum[100005],s[100005];
double p[100005];
int main(){
	int n,m;
	while(cin>>n>>m)
	{
		int a;
		sum[0]=0;
		s[0]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a);
			sum[i]=sum[i-1]+a;
			s[i]=s[i-1]+a*a;
		}
		
		for(int i=1;i<=n-m+1;++i)
		{
			double a1 = s[i+m-1]-s[i-1];
			double a2 = sum[i+m-1]-sum[i-1];
			a2=a2*1.0/m;
			double a3=a2*a2;
			a3*=m;
			a2= 2*a2*(sum[i+m-1]-sum[i-1]);
			//cout<<a1<<' '<<a3<<' '<<a2<<endl;
			double ans = a1+a3-a2;
			ans/=(m-1);
			ans = fabs(ans);
			ans = sqrt(ans);
			//cout<<ans<<endl;
			printf("%.8f\n",ans);
		}
	}
	return 0;
}
