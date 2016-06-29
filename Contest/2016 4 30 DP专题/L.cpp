#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1<<16];
ll a[1<<16];
ll f[1<<16];
char w[30];
ll st;
int n;


int main()
{
	int t;
	cin>>t;
	int ff=1;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		scanf("%s",w);
		ll num=0;
		for(int i=n-1;i>=0;--i)num=num*2+(w[i]-'0');
		st = num;
		//cout<<st<<endl;
		for(int i=0;i<n;++i)
		{
			scanf("%s",w);
			num=0;
			for(int j=n-1;j>=0;--j)num=num*2+((w[j]=='0')? 0:1);
			a[i]=num;
			//cout<<num<<endl;
		}
		for(int i=0;i<(1<<n);++i)
		{
			f[i]=st;
			for(int j=0;j<n;++j)
			{
				if(i & (1<<j))f[i]|=a[j];
			}
		}
		dp[0]=1;
		for(int i=1;i<(1<<n);++i)
		{
			for(int j=0;j<n;++j)
			{
				if(i&(1<<j) && f[i^(1<<j)]&(1<<j))
					dp[i]+=dp[i^(1<<j)];
			}
		}
		cout<<"Case "<<ff++<<": ";
		//for(int i=0;i<(1<<n);++i)cout<<dp[i]<<endl;
		cout<<dp[(1<<n)-1]<<endl;
	}	
} 
/*
3
1
1
1
2
11
01
10
3
110
011
100
000
*/
