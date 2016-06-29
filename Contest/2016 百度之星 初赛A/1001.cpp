#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define ll long long

int a[10005];
int vis[10005]; 


int main()
{
	ll x,m,k,c;
	int t;
	cin>>t;
	int f=1;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cin>>x>>m>>k>>c;
		ll sum=0;
		int n=0;
		while(1)
		{
			sum%=k;
			if(vis[sum]==1)break;
			vis[sum]=1;
			a[n++]=sum;
			sum=sum*10+x;
		}
		//for(int i=0;i<n;++i)cout<<a[i]<<' ';
		//cout<<endl;
		m%=(n);
		//cout<<m<<endl;
		printf("Case #%d:\n",f++);
		if(a[(m)%n]==c)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
