#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	sort(a,a+n);
	int x=a[n-1];
	int z=0,y=0;
	
	int mi=9999999,ma=0;
	for(int i=n-1;i>=0;--i)
	{
		if(z==k)break;
		if(a[i]==x)
		{
			z++;
			y=z*x;
		}
		else 
		{
			x=a[i];
			z++;
			y=z*x;
		}
	//	cout<<y<<endl;
		if(y<ma)continue;
		ma=max(ma,y);
		mi=x;
	}
	cout<<mi<<' '<<ma<<endl;
	return 0;
}
