#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ans=n-sqrt(n);
		//cout<<ans<<endl;
		if(n%2==0)ans++;
		cout<<ans<<endl;
	}
}
