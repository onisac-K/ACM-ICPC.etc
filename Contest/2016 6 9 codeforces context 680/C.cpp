#include<bits/stdc++.h>
using namespace std;

int prime[105];
int p[105];

int main()
{
	int ans=0;
	memset(prime,0,sizeof(prime));
	for(int i=2;i<100;++i)
	{
		if(prime[i]==0)
		for(int j=i*i;j<=100;j+=i)prime[j]=1;
	}
	int q=0;
	for(int i=2;i<=100;++i)
	{
		if(prime[i]==0)p[q++]=i;
	}
	//for(int i=0;i<q;++i)cout<<p[i]<<endl;
	string s;
	int a[100];
	int k=0;
	for(int i=2;i<=7;++i)
	{
		cout<<i<<endl;
		cin>>s;
		if(s=="yes")
		{
			ans++;
			a[k++]=i;
		}
	}
	int flag=0;
	if(ans==0)cout<<"prime"<<endl;
	if(ans>=2)cout<<"composite"<<endl;
	else 
	{
		cout<<a[0]*a[0]<<endl;
		cin>>s;
		if(s=="yes")
		{
			flag=1;
		}
		for(int i=4;i<q&&p[i]<=50;++i)
		{
			if(flag==1)break;
			cout<<p[i]<<endl;
			cin>>s;
			if(s=="yes")
			{
				flag=1;
				break;
			}
		}
		if(flag==1)cout<<"composite"<<endl;
		else cout<<"prime"<<endl;
	}
	
	fflush(stdout);
	return 0;
}
