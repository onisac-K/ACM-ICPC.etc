#include<iostream>
#include<algorithm>
#include<cstdio>
#include <cmath>  
using namespace std;

int a[100005];

int main()
{
	int n,k;
	cin>>n;
	int l = 0,r = 0;
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		r = max(r,a[i]);
	}
	cin>>k;
	if(k == 1){
		cout<<r<<endl;
		return 0;
	}
	int ans = r;
	while(l<=r){
		int mid = (l+r)>>1;
		int time = 0;
		for(int i=0;i<n;++i){
			if(a[i] <= mid)continue;
			else {
				time += ceil((a[i]-mid)*1.0/(k-1));
				if(time>mid)break; 
			}
		}
		//cout<<mid<<' '<<time<<endl;
		if(time<=mid){
			ans = min(ans,mid);
			r = mid - 1; 
		}
		else l = mid + 1;
	}
	cout<<ans<<endl;
	return 0;
}
