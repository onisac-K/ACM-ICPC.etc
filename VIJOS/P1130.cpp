#include<bits/stdc++.h>
using namespace std;
int dp[1005];
int main()
{
    int n;
    cin>>n;
    dp[1]=1;
    dp[2]=2;
    dp[3]=2;
    for(int i=4;i<=n;++i)
    {
        dp[i]=1;
        for(int j=1;j<=i/2;++j)dp[i]+=dp[j];
    }
    cout<<dp[n]<<endl;
}
