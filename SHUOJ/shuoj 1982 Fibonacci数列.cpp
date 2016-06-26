#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f[100];

int main()
{
	f[0]=0;
	f[1]=1;
	for(int i=2;i<90;++i)f[i]=f[i-1]+f[i-2];
	//cout<<f[89]<<endl;
	ll n;
	while(cin>>n)
	{
		if(n==-1)break;
		int i;
		for(i=0;i<90;++i)if(f[i]==n)break;
		if(i<90)cout<<i<<endl;
		else cout<<"Not a Fibonacci number."<<endl;	
	}
	return 0;
} 
