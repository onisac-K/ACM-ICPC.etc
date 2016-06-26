#include<bits/stdc++.h>
using namespace std;

int a[100005];
int sum[100005];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		sum[n-1]=0;
		for(int i=n-2;i>=0;--i)sum[i]=sum[i+1]+(a[i+1]>0);
		int ans=0;
		for(int i=0;i<n;++i)ans=max(ans,sum[i]+a[i]);
		printf("%d\n",ans);
	}
}
