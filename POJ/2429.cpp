#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define ll long long 

ll gcd(ll a, ll b){
	return (b==0 ? a:gcd(b,a%b));
}

int main()
{
	ll n,m;
	while(cin>>n>>m){
		ll k = n*m;
		ll a = n,b;
		while(1){
			b = k/a;
			if(b%n==0)break;
			a+=n;
		}
		cout<<a<<' '<<b<<endl;
	}
}
