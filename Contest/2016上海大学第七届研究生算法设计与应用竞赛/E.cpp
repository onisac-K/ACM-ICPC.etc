#include<bits/stdc++.h>
using namespace std;

int a[1005] ;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int k=0;
		while(n>0)
		{
			a[k++]=n%2;
			n/=2;
		}
		int num=0;
		for(int i=0;i<k;++i)if(a[i]==1)num++;
		int s=0;
		for(int i=0;i<num;++i)s=s*2+1;
		printf("%d\n",s+1);
	 } 
	return 0;
}
