#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[2005][2005];
char a[2005];
int cost[30];

int main()
{
	int n,m;
	cin>>n>>m;
	scanf("%s",a+1);
	char c[2];
	int v1,v2;
	for(int i=1;i<=n;++i){
		scanf("%s %d %d",c,&v1,&v2);
		cost[(int)(c[0]-'a')]=min(v1,v2);
		//cout<<v1<<' '<<v2<<endl;
	}
	memset(dp,0x3f3f3f3f,sizeof(dp));
	for(int i=1;i<=m;++i)dp[i][i]=0;
	for(int i=m-1;i>=1;--i){
		for(int j=i+1;j<=m;++j)
		{
			if(a[i]==a[j]){
				if(j==i+1)dp[i][j]=0;
				else dp[i][j]=dp[i+1][j-1];
				continue;
			}
			dp[i][j]=min(dp[i+1][j]+cost[a[i]-'a'],dp[i][j-1]+cost[a[j]-'a']);
			//cout<<a[i]<<' '<<a[j]<<' '<<dp[i][j]<<endl;
		}
	}
	cout<<dp[1][m]<<endl;
	return 0; 
} 
 
