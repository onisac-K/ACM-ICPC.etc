#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int N = 100000;
int dp[4*N];
int a[105],b[105];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		scanf("%d%d",&a[i],&b[i]);
	}
	
	for(int i=0;i<=N*2;++i)dp[i] = -1*INF;
	dp[N] = 0;
	for(int i=0;i<n;++i){
		if(a[i]>0){
			for(int j=2*N;j>=a[i];--j){
				if(dp[j-a[i]]!=-INF)
					dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
			}
		}
		else {
			for(int j=a[i];j-a[i]<=2*N;++j){
				if(dp[j-a[i]]!=-INF){
					//cout<<a[i]<<' '<<j-a[i]<<endl;
					dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
				}
			}
		}
	}
	int ans = 0;
	for(int i=N;i<2*N;++i){
		if(dp[i]>=0){
			ans = max(ans,i-N+dp[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
