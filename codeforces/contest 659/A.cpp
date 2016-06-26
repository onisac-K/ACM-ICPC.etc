#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	while(b<0)b+=n;
	b%=n;
	int c=a+b;
	int ans=fabs((c%n));
	if(ans==0)ans=n;
	cout<<ans<<endl;
}
