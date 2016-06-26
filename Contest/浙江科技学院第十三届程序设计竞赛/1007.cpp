#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c(int x)
{
	if(x==1)return 0;
	return x*(x-1)/2;
}

char a[105][105];
int x[105];
int y[105];

int main()
{
	int n;
	while(cin>>n)
	{
		memset(x,0,sizeof(x));		
		memset(y,0,sizeof(y));
		for(int i=0;i<n;++i)scanf("%s",a[i]);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)if(a[i][j]=='C')x[i]++;
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)if(a[j][i]=='C')y[i]++;
		}
		ll ans=0;
		for(int i=0;i<n;++i)ans+=(c(x[i])+c(y[i]));
		cout<<ans<<endl;
	}
	return 0;
}
