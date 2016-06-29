#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[10],b[10]; 

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;++i)a[i%5]++;
	for(int i = 1;i<=m;++i)b[i%5]++;
	ll ans;
	ans = a[0]*b[0]+a[1]*b[4]+a[2]*b[3]+a[3]*b[2]+a[4]*b[1];
	cout<<ans<<endl;
	return 0;
} 
