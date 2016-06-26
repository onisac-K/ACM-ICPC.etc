#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a,ll b)
{
	return (b==0)? a:gcd(b,a%b);
}


int main()
{
	int x,y;
	
	cin>>x>>y;
	long long s=x*y;
	int num=0;
	for(int i=x;i<=y;i+=x)
	{
		if(s%i==0 && s/i<=y && s/i>=x && y%i==0 && gcd(s/i,i)==x)num++;
	}
	cout<<num<<endl;
}
