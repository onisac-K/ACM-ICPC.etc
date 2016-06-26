#include <bits/stdc++.h>
using namespace std;
char a[105];
int num1[105];
int num2[105];
int hui[105];

bool ok(int n)
{
	for(int i=0;i<n;++i)if(hui[i]!=hui[n-1-i])return false;
	return true;
}

bool o(int n)
{
	for(int i=0;i<n;++i)if(a[i]!=a[n-1-i])return false;
	return true;
}

int main()
{
	int n;
	cin>>n;
	scanf("%s",a);
	int L=strlen(a);
	if(o(L))
	{
		cout<<"STEP=0"<<endl;
		return 0;
	}
	for(int i=0;i<L;++i)
	{
		if(a[i]>='0'&&a[i]<='9')num1[i]=(a[i]-'0');
		else num1[i]=(a[i]-'A')+10;
	}
	for(int i=0;i<L;++i)num2[i]=num1[L-1-i];
	
	int c=1;
	while(c<=30)
	{
		int k=0;
		memset(hui,0,sizeof(hui));
		for(int i=L-1;i>=0;--i)
		{
			hui[k]+=(num1[i]+num2[i]);
			//cout<<hui[k]<<endl;
			if(hui[k]>=n)
			{
				hui[k+1]+=hui[k]/n;
				hui[k]%=n;
			}
			k++;
		}
		while(hui[k]!=0)k++;
		if(hui[k+1]!=0)k=k+1;
		/*for(int i=0;i<L;++i)cout<<num1[i]<<' ';
		cout<<endl;
		for(int i=0;i<L;++i)cout<<num2[i]<<' ';
		cout<<endl;
		for(int i=0;i<k;++i)cout<<hui[i]<<' ';
		cout<<endl<<endl;*/
		if(ok(k))break;
		else 
		{
			L=k;
			for(int i=0;i<k;++i)
			{
				num1[i]=hui[i];
				num2[i]=hui[k-1-i];
			}
		}
		c++;
	}
	if(c>30)cout<<"Impossible!"<<endl;
	else cout<<"STEP="<<c<<endl;
}
