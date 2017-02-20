#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005]; 
int a[1005];
const int mod = 1000000007;

int main()
{
      
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<1005;++i)
    {
        dp[0][i]=1;
        for(int j=1;j<=i;++j)
        {
            dp[j][i]=dp[j-1][i-1]+dp[j][i-1];
            dp[j][i]%=1000000007;
        }
    }
    int n;
    while(cin>>n){
    	for(int i=1;i<=n;++i)
    		scanf("%d",&a[i]);
		double ans = 0;
		if(n==1){
			printf("%.5f\n",a[1]*1.0);
			continue;
		}
		
		for(int i=1;i<=n;++i){
			if(i==1 || i==n){
				ans += a[i]*1.0/2;
			}
			else ans += a[i]*1.0/3;
		}
		printf("%.5f\n",ans);
	}
    
    return 0;
}  

