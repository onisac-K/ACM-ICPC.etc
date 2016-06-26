#include<bits/stdc++.h>
using namespace std;
#define Max 1001000
#define ll long long
int euler[Max];
int a[Max];

void Init(){ 
    euler[1]=1;
    for(int i=2;i<Max;i++)
    euler[i]=i;
    for(int i=2;i<Max;i++)
        if(euler[i]==i)
        for(int j=i;j<Max;j+=i)
            euler[j]=euler[j]/i*(i-1);
}



int main()
{
	Init();
	int ma=0;
	
	for(int i=2;i<=Max;++i)
	{
		if(a[euler[i]]==0)
		{
			ma=max(ma,euler[i]);
			a[euler[i]]=i;
		}
	}
	int mi=ma;
	//cout<<mi<<endl;
	for(int i=ma;i>=1;--i)
	{		
		if(a[i]<mi&&a[i]!=0)
		{
			mi=a[i];
		}
		else a[i]=mi;
	}
	//for(int i=999900;i<=1000000;++i)cout<<i<<' '<<a[i]<<endl;
	int t;
	cin>>t;
	int f=1;
	while(t--)
	{
		int n;
		cin>>n;
		int x;
		ll sum=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&x);
			sum+=a[x];
		}
		printf("Case %d: %lld Xukha\n",f++,sum);
	}
}
