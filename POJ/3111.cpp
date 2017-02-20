#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long

const double EPS=1.0e-6;

double a[100005],b[100005];
struct node{
	double s;
	int id;
	bool operator< (const node & c)const{
		return s<c.s;
	}
}c[100005];

int ans[100005];

int main(){
	int n,k;
	while(cin>>n>>k){
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&a[i],&b[i]);
		double l = 0 ,r = 0x3f3f3f3f;
		while(1){
			if(r-l<EPS)break;
			double mid = (l+r)/2;
			for(int i=0;i<n;++i){
				c[i].s = a[i]-mid*b[i];
				c[i].id = i+1;
			}
			sort(c,c+n);
			double sum = 0;
			for(int i=n-k;i<n;++i)sum+=c[i].s;
			if(sum>0){
				l = mid;
			} 
			else r = mid;
		} 
		int cnt = 0;
		for(int i=n-k;i<n;++i)ans[cnt++] = c[i].id;
		sort(ans,ans+cnt);
		for(int i=0;i<cnt;++i){
			if(i<cnt-1)printf("%d ",ans[i]);
			else printf("%d\n",ans[i]);
		}
	}
	return 0;
} 
