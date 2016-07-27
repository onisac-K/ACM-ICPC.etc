#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int a[40005];
int dp[40005];

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		dp[1] = a[1];
		int len = 1;
		for(int i=2;i<=n;i++){
			int l=1,r=len;
			while(l<=r){
			int mid=(l+r)>>1;
			if(dp[mid]<a[i])
				l=mid+1;
				else
				r=mid-1;
     		}
		    dp[l]=a[i];
		    len=max(len,l);
		}
		cout<<len<<endl;
	}
	return 0;
}
