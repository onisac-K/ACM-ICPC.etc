#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int f = 1;
	for(int i = 1;i<=n;++i)
	{
		if(a[i]>=f)
		{
			a[i]=f;
			f++;
		}
	}
	cout<<f<<endl;
	return 0;
} 
