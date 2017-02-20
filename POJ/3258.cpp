#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[50005];

int main()
{
	int L,N,M;
	cin>>L>>N>>M;
	a[0] = 0;
	a[N+1] = L;
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	sort(a+1,a+N+1);
	int l = 0,r = L;
	int ans = 0;
	while(l<=r){
		int mid = (l+r)/2;
		int st = a[0],cnt = 0;
		for(int i=1;i<=N+1;++i){
			if(a[i]-st<mid){
				//cout<<a[i]<<endl;
				cnt++;
			}
			else {
				st = a[i];
			}
		}
		//cout<<mid<<' '<<cnt<<endl;
		if(cnt > M) r = mid-1;
		else {
			ans = max(ans,mid);
			l = mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
