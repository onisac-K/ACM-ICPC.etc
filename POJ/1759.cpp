#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;double a;
	while(cin>>n>>a){
		double l = 0,r = 1000000000;
		double ans = r;	
		while(1){
			if(r-l<=0.000001)break;
			double mid = (l+r)/2;
			//cout<<l<<' '<<r<<' '<<mid<<endl;
			double x = mid,B,A = a;
			int flag = 0;
			for(int i=3;i<=n;++i){
				B = 2*(x+1) - A;
				A = x;
				x = B; 
				if(B<0){
					flag = 1;
					break;
				}
			}
			//cout<<flag<<endl;
			if(flag == 1){
				l = mid;
			}
			else {
				ans = min(ans,B);
				r = mid;
			}
		} 
		printf("%.2f\n",ans);
	}
	return 0;
}
