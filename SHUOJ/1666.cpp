#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;++i)scanf("%d",&a[i]);

		sort(a,a+n);
		int x = a[n/2];
		int ans = 0;
		for(int i=0;i<n;++i)
		{
			ans+=fabs(a[i]-x);
		}
		cout<<ans<<endl;
	}
	return 0;
}
