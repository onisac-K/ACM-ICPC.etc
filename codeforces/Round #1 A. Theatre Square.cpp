#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,m,a;
	cin>>n>>m>>a;
	ll k1=n/a;
	if(n%a!=0)k1++;
	ll k2=m/a;
	if(m%a!=0)k2++;
	cout<<k1*k2<<endl;
	return 0;
}
