#include<bits/stdc++.h>
using namespace std;

int sum[5000001*3];

bool ok(int i)
{
	int x;
	while(i>0)
	{
		x = i%10;
		i/=10;
		if(x==7)return true;
	}
	return false;
}

int main()
{
	for(int i=1;i<=5000001*3;++i)
	{
		if(i%7==0 || ok(i))sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	}
	//for(int i=1;i<50;++i)cout<<i<<" "<<sum[i]<<endl;
	int n,m;
	while(cin>>m>>n)
	{
		int i;
		for(i=m+1;i<=5000001*3;++i)
		{
			if(sum[i]-sum[m]==n)break;
		}
		printf("%d\n",i);
	}
	return 0;
}
