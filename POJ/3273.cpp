#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[100005];

int main()
{
	int n,m;
	cin>>n>>m;
	int L = 0;
	int M = 0;
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		L += a[i];
		M = max(M,a[i]);
	}
	
	//sort(a,a+n);
	int l = M,r = L,ans = L+1;
	while(l<=r){
		int mid = (l+r)>>1;
		int st = 0,cnt = 0;
		for(int i=0;i<n;++i){
			if(st+a[i]<=mid){
				st+=a[i];
			}
			else{
				//cout<<st<<endl;
				cnt++;
				st = a[i];
			}
		}
		cnt++;
		//cout<<mid<<' '<<cnt<<endl;
		if(cnt>m){
			l = mid+1;
		}
		else {
			ans = min(ans,mid);
			r = mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
