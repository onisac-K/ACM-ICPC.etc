#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool is(int s)
{
	int k = s*s;
	while(s>0)
	{
		int a = s%10;
		int b = k%10;
		//cout<<a<<' '<<b<<endl;
		if(a!=b)return false;
		s/=10;
		k/=10;
	}
	return true;
}

int main()
{
	int n;
	int f=1;
	while(cin>>n)
	{
		printf("Case %d: %d, ",f++,n);
		if(is(n))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;	 
	}
	return 0;
}
