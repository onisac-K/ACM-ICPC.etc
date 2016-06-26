#include<bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	int ans=0;
	for(int i=0;i<n;++i)
	{
		if(a[i]>sum)
		{
			a[i+1]+=(a[i]-sum);
			ans++;
		}
		else if(a[i]<sum)
		{
			a[i+1]-=(sum-a[i]);
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
