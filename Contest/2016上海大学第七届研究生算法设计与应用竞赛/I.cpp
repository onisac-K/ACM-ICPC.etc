#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a,ll b)
{
	return b==0? a:gcd(b,a%b);
}


int main()
{
	int t;
	cin>>t;
	int a,b;
	while(t--)
	{
		cin>>a>>b;
		cout<<a/gcd(a,b)<<endl;
	}
	
	return 0;
}
