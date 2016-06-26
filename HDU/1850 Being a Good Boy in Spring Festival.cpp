#include<bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
	int n;
	while(cin>>n&&n)
	{
		int sum=0;
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
			sum^=a[i];
		}
		int ans=0;
		for(int i=0;i<n;++i)
		{
			if(a[i]>(a[i]^sum))ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
