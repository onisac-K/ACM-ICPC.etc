#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)ans+=(n-i+1)*(n-i+1);
	cout<<ans<<endl;
	return 0;
}
