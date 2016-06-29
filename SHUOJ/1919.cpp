#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[55][25][2][50]; 
int a[55][55];
ll n ,k;

ll dfs(ll n2,ll n1,ll d,ll k1)
{
	//cout<<n2<<' '<<n1<<' '<<d<<' '<<k1<<endl;
	if(a[n2][n1]==0)return dp[n2][n1][d][k1]=0;
	if(dp[n2][n1][d][k1]!=0)return dp[n2][n1][d][k1];
	if(k1>2*k-1 || d>=2 ||  n2>2*n || k1>n2)
		return dp[n2][n1][d][k1]=0;
	if(n2==0 && n1==1 && d==1 && k1==0)
		return  dp[n2][n1][d][k1]=1;
	else if(n2==0)return dp[n2][n1][d][k1]=0;
	if(n1>n&&k1>1)return dp[n2][n1][d][k1]=0;
	ll ans = 0;
	if(n1==1 && d==0)return dp[n2][n1][d][k1]=0;
	if(n1==1 && d==1)
	{
		if(n2==2*n)ans += dfs(n2-1,2,0,k1);
		else ans += dfs(n2-1,2,0,k1-1);
	}
	else if(n1>1)
	{
		if(d==1){
			if(k1-1>=0)ans += dfs(n2-1,n1+1,0,k1-1);
			ans += dfs(n2-1,n1-1,1,k1);
		}
		if(d==0){
			//cout<<123<<endl;
			ans += dfs(n2-1,n1+1,0,k1);
			if(k1-1>=0)ans += dfs(n2-1,n1-1,1,k1-1);
		}	
	}
	return dp[n2][n1][d][k1]=ans;
}

int main()
{
	int t;
	
	cin>>t;
	
	while(t--){
		scanf("%d%d",&n,&k);
	
		 int i,j,kk;
        for(i=0,j=1;i<=n;i+=2,j++)
            for(kk=1;kk<=j;kk++){
                a[i][2*kk-1]=1;
                a[2*n-i][2*kk-1]=1;
            }
        for(i=1,j=1;i<=n;i+=2,j++)
            for(kk=1;kk<=j;kk++){
                a[i][2*kk]=1;
                a[2*n-i][2*kk]=1;
            }
    	if(n==1)cout<<1<<endl;
		else {
			printf("%lld\n",dfs(2*n,1,1,2*k-1));
		}
	}
	return 0;
}
