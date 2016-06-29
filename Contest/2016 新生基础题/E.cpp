#include<bits/stdc++.h>
using namespace std;

double s[15];

int main()
{
	char c;
	double a;
	int n=0;
	int f=1;
	while(scanf("%lf%c",&a,&c)!=EOF)
	{
		if(c==' '){
			s[n++]=a;
		}
		if(c=='\n')
		{
			s[n++]=a;
			double sum=0;
			//cout<<n<<endl;
			//for(int i=0;i<n;++i)cout<<s[i]<<' ';cout<<endl;
			for(int i=0;i<n;++i)sum+=s[i];
			double ans1=sum/n;
			sum=1;
			for(int i=0;i<n;++i)sum*=s[i];
			double q = 1.0/n;
			double k=sum;
			if(sum<0)sum*=-1;
			double ans2=pow(sum,1.0/n);
			if(k<0 && (n)%2==1)
			{
				if(ans2>0)ans2*=-1;
			}
			if(k<0 && (n)%2==0)
			{
				printf("Case %d: %.1f, None\n",f++,ans1);
			}
			else printf("Case %d: %.1f, %.1f\n",f++,ans1,ans2);
			n=0; 
		}
	}
	return 0;
}
