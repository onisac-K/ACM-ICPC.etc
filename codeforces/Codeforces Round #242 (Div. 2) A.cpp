#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char a[205];
	scanf("%s",a);
	int x=0,X=0;
	for(int i=0;i<n;++i)
	{
		if(a[i]=='x')x++;
		else X++;
	}
	int ans=0;
	if(x<n/2)
	{
		ans=n/2-x;
		int k=0;
		for(int i=0;i<n&&k<ans;++i)
		{
			if(a[i]=='X')
			{
				a[i]='x';
				k++;
			}
		}
	}
	else 
	{
		ans=n/2-X;
		int k=0;
		for(int i=0;i<n&&k<ans;++i)
		{
			if(a[i]=='x')
			{
				a[i]='X';
				k++;
			}
		}
	}
	cout<<ans<<endl;
	cout<<a<<endl;
	return 0;
} 
