#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long

double a[1005],b[1005];
double c[1005];

int main(){
	int n,k;
	while(cin>>n>>k && (n||k)){
		for(int i=0;i<n;++i)
			scanf("%lf",&a[i]);
		for(int i=0;i<n;++i)
			scanf("%lf",&b[i]);
		double l = 0 ,r = 1;
		double ans = 0;
		while(1){
			if(r-l<0.0001)break;
			double mid = (l+r)/2;
			for(int i=0;i<n;++i){
				c[i] = a[i]*1.0-mid*b[i];
			}
			sort(c,c+n);
			double sum = 0;
			for(int i=k;i<n;++i)sum+=c[i];
			if(sum>0){
				ans = max(ans,mid);
				l = mid;
			} 
			else r = mid;
		} 
		ans*=100;
		printf("%.0f\n",ans);
	
	}
	return 0;
} 
