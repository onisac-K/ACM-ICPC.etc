#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[60][3][3];
 
int main()
{
    dp[1][0][0] = 1;
    dp[1][1][1] = 1;
    dp[1][2][2] = 1;
    for(int i=1;i<=60;++i){
    	for(int j=0;j<3;++j){
    		for(int k=0;k<3;++k){
    			for(int w=0;w<3;++w){
    				if(k==w)continue;
					dp[i][j][k] += dp[i-1][j][w];
				}
			}
		}
	}
	int n;
    while(cin>>n){
    	ll ans = 0;
    	if(n == 1){
    		cout<<3<<endl;
    		continue;
		}
    	for(int i=0;i<3;++i){
    		for(int j=0;j<3;++j)
    			if(i!=j)ans += dp[n][i][j];
		}
		cout<<ans<<endl;
	}
    return 0;
} 
