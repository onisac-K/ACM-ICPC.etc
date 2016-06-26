#include<bits/stdc++.h>
using namespace std;
int main()
{
	int d,h,m,s,d2,h2,m2,s2;
	while(cin>>d>>h>>m>>s)
	{
		cin>>d2>>h2>>m2>>s2;
		int s1=s+s2;
		m+=s1/60;
		s1%=60;
		int m1=m+m2;
		h+=m1/60;
		m1%=60;
		int h1=h+h2;
		d+=h1/24;
		h1%=24;
		int d1=d+d2;
		cout<<d1<<' '<<h1<<' '<<m1<<' '<<s1<<endl;
	}
	return 0;
}
