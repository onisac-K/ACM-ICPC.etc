#include<bits/stdc++.h>
using namespace std;
#define CLR(x) memset(x,0,sizeof(x))
char a[1005];
int dp[1005][30];
int vis[1005][30];
int num[1005];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,0x3f3f3f,sizeof(dp));
		CLR(vis);
		CLR(num);
		int k;
		cin>>k;
		scanf("%s",a);
		int L = strlen(a);
		for(int i=0;i<L;i+=k)
		{
			for(int j=i;j<i+k;++j)
			{
				if(vis[i][a[j]-'a']==0)
				{
					//cout<<a[j]<<endl;
					vis[i][a[j]-'a']=1;
					num[i]++;
				}
			} 
		}
		for(int i=0;i<=26;++i)
		{
			if(vis[0][i]==1)
			{
				dp[0][i]=num[0];
			}
		}
		for(int i=k;i<L;i+=k)
		{
			for(int j=0;j<=26;++j)
			{
				if(vis[i-k][j]&&vis[i][j])
				{
					//cout<<(char)(j+'a')<<endl;
					if(num[i]==1)dp[i][j]=min(dp[i][j],dp[i-k][j]);
					else 
					for(int kk=0;kk<=26;++kk)
					{
						if(j==kk)continue;
						if(vis[i][kk])
						{
							dp[i][kk]=min(dp[i][kk],dp[i-k][j]+num[i]-1);
						}
					}
				}
				else if(vis[i-k][j])
				{
					for(int kk=0;kk<=26;++kk)
					{
						if(vis[i][kk])
						{
							dp[i][kk]=min(dp[i][kk],dp[i-k][j]+num[i]);
						}
					}
				}
			}
		}
		int ans=100000000;
		/*for(int i=0;i<L;i+=k)
		{
			for(int j=0;j<=26;++j)cout<<(dp[i][j]==(1061109567)? 0:dp[i][j])<<' ';
			cout<<endl;
		}*/
		for(int i=0;i<=26;++i)ans=min(ans,dp[L-k][i]);
		cout<<ans<<endl;
	}
} 
/*
2
5 helloworld
7 thefewestflops
*/
