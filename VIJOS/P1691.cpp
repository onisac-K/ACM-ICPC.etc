#include<bits/stdc++.h>
using namespace std;

int a[10005];

int main()
{
	int n;
	int x,y;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		a[i]=y;
	}
	sort(a,a+n);
	x=a[n/2];
	int ans=0;
	for(int i=0;i<n;++i)ans+=fabs(a[i]-x);
	int ans2=0;
	x=a[n/2+1];
	for(int i=0;i<n;++i)ans2+=fabs(a[i]-x);
	ans=min(ans,ans2);
	cout<<ans<<endl;
}
