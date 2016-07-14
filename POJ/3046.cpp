#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[1000005];
int cnt[1000005];
int sum[10005];
const int mod = 1000000;
int main()
{
	int t,a,s,b;
	cin>>t>>a>>s>>b;
	int q;
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<a;++i){
		cin>>q;
		cnt[q]++;
	}	
	for(int i=1;i<=t;++i)sum[i]=sum[i-1]+cnt[i];
	//cout<<endl;
	dp[0]=1;
	for(int i=1;i<=t;++i)
	{
		//memset(cnt,0,sizeof(cnt));
		for(int j=sum[i];j>=1;--j){
			for(int w=1;w<=cnt[i];++w)
				if(j-w>=0)dp[j]+=dp[j-w];
				else break;
			dp[j]%=mod;
		}
		/*for(int j=1;j<=sum[i];++j){
			
			for(int w=1;w<=j;++w)
				if(w+num[i]>=j)dp[i][j]+=dp[i-1][w];
				else break;
			if(num[i]>=j)dp[i][j]++;		
			//dp[i][j]+=dp[i-1][j-1]+dp[i-1][j]+(num[i]>=j? 1:0);
			dp[i][j]%=mod;
		}*/
	}
	/*for(int i=1;i<=k;++i){
		for(int j=1;j<=10;++j)cout<<dp[i][j]<<' ';
		cout<<endl;
	}*/
	int ans = 0;
	for(int i=s;i<=b;++i){
		ans += dp[i];
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
 } 
