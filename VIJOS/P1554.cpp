#include<bits/stdc++.h>
using namespace std;

int dp[1005][2010];

void debug(int t,int n)
{
	for(int i=1;i<=2*n;++i)
	{
		if(i<2*n)
		{
			printf("%d ",dp[t][i]);
		}
		else printf("%d\n",dp[t][i]);
	}
	cout<<endl;
}

int main()
{
	int n,t;
	cin>>n>>t;
	int x;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		dp[0][2*i-1]=x;
	}
	int k=0;
	for(int i=1;i<=t;++i)
	{
		//debug(i-1,n);
		for(int j=1;j<=2*n;++j)
		{
			if(k%2==0)
			{
				if(j&1)continue;
				if(j%2==0)
				{
					if(j<2*n)
					{
						if((dp[i-1][j-1]+dp[i-1][j+1])%2==0)
							dp[i][j]=1;
						else dp[i][j]=2; 
					}
					else if(j==2*n)
					{
						if((dp[i-1][j-1]+dp[i-1][1])%2==0)
							dp[i][j]=1;
						else dp[i][j]=2; 
					}
				}
			}
			else 
			{
				if(j%2==0)continue;
				if(j%2==1)
				{
					if(j>1)
					{
						if((dp[i-1][j-1]+dp[i-1][j+1])%2==0)
							dp[i][j]=1;
						else dp[i][j]=2; 
					}
					else if(j==1)
					{
						if((dp[i-1][2*n]+dp[i-1][2])%2==0)
							dp[i][j]=1;
						else dp[i][j]=2; 
					}
				}
			}
		}
		if(k%2==0)
		{
			for(int j=1;j<=2*n;++j)
			{
				if(j%2==1)dp[i][j]=0; 
			}
		}
		else 
		{
			for(int j=1;j<=2*n;++j)
			{
				if(j%2==0)dp[i][j]=0; 
			}
		}
		k++;
	}
	for(int i=1;i<=2*n;++i)
	{
		if(i<2*n)
		{
			printf("%d ",dp[t][i]);
		}
		else printf("%d\n",dp[t][i]);
	}
}
