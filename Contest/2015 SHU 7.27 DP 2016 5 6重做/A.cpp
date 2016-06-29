#include<bits/stdc++.h>
using namespace std;

char a[1005],b[1005];
int dp[1005][1005];

int main()
{
	while(~scanf("%s %s",a,b))
	{
		int la=strlen(a);
		int lb=strlen(b);
		//int n = max(la,lb);
		for(int i=1;i<=la;++i)
		{
			for(int j=1;j<=lb;++j)
			{
				if(a[i-1]==b[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else 
				{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		cout<<dp[la][lb]<<endl;
	}
} 
