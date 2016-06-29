#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	int f = 1;
	while(cin>>n>>m)
	{
		int num[100];
		int x=0;
		while(n>0)
		{
			num[x++]=n%m;
			n/=m;
		}
		printf("Case %d: ",f++);
		for(int i=x-1;i>=0;--i)
		{
			if(num[i]<=9)cout<<num[i];
			else {
				char c = (char)(num[i]-10+'A');
				cout<<c;
			}
		}
		cout<<endl;
	}
	return 0;
}
