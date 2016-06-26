#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,n,m,k;
		cin>>a>>b>>n>>m>>k;
		int num=n*m;
		num-=k;
		int va=0;
		double s=a*1.0/n;
		if(num<0)
		{
			cout<<0<<endl;
			continue;
		}
		if(s>b)
		{
			va=num*b;
			cout<<va<<endl;
			continue;
		}
		if(num>n)
		{
			int q=num/n;
			num-=q*n;
			va+=q*a;
		}
		int v2=num*b;
		if(v2<a)
		{
			va+=v2;
		}
		else va+=a;
		cout<<va<<endl;
	}
}
