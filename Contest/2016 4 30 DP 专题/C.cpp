#include<bits/stdc++.h>
using namespace std;
#define CLR(X) memset(X,0,sizeof(X))
const int maxn = 1<<16+5;

int a[maxn];
int dp[maxn];
int c[maxn];

int main()
{
	int n;
	int f=1;
	while(cin>>n&&n)
	{
		CLR(a);
		CLR(c);
		CLR(dp);
		int m,x;
		for(int i=0;i<n;++i)
		{
			cin>>m;
			c[i]=(1<<i);
			for(int j=0;j<m;++j)
			{
				scanf("%d",&x);
				c[i]|=(1<<x);	
			}
		}
		for(int i=0;i<(1<<n);++i)
		{
			for(int j=0;j<n;++j)
			{
				if(i&(1<<j))a[i]|=c[j];
			}
		}
		for(int i=0;i<(1<<n);++i)
		{
			for(int j=i;j;j=(j-1)&i)
			{
				if(a[j]==((1<<n)-1)){
					dp[i]=max(dp[i],dp[i^j]+1);
					//cout<<i<<' '<<dp[i]<<endl; 
				}
			}
		}
		printf("Case %d: ",f++);
		cout<<dp[(1<<n)-1]<<endl;
	}
}

/*
3
2 1 2
2 0 2
2 0 1
4
1 1
1 0
1 3 
1 2
0 

*/
