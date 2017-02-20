#include<bits/stdc++.h>
using namespace std;
#define ll long long

char a[100005],b[100005];
int f[100005];
int ans[100005];
int cnt;

void getFail(char* P, int* f)  
{  
    int m = strlen(P);  
    f[0] = 0;  
    f[1] = 0;  
    for(int i = 1; i < m; i++)  
    {  
        int j = f[i];  
        while(j && P[i] != P[j])  
        {  
            j = f[j];  
        }  
        f[i + 1]=P[i]==P[j]?j+1:0;  
	    }  
}  
      
int find(char* T, char*P, int*f)  
{  
    int n = strlen(T), m = strlen(P);  
    getFail(P, f);  
    int j = 0;  
    for(int i = 0; i < n; i++)  
    {  
        while(j && P[j] != T[i])  
        {  
            j = f[j];  
        }  
        if(P[j] == T[i])  
        {  
        	j++;  
        }  
        if(j == m)  
        {  
            ans[i] = 1;
			j = f[j]; 
        }  
    }  
    return -1;  
}  

int dp[100005][2];
int pos[100005];

void debug(int n){
	for(int i=0;i<n;++i)cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
}

int main()
{
	int t;
	cin>>t;
	int fl = 1;
	while(t--){
		scanf("%s%s",&a,&b);
		getFail(b,f);
		memset(ans,0,sizeof(ans));
		find(a,b,f);
		cnt = 0;
		int l = strlen(a);
		int L = strlen(b);
		for(int i=0;i<l;++i){
			if(ans[i])pos[cnt++] = i;
		}
		dp[0][0] = dp[0][1] = 1;
		for(int i=1;i<cnt;++i){
			if(pos[i]-pos[i-1]>=L){
				dp[i][0] = dp[i-1][0]+dp[i-1][1];
				dp[i][1] = dp[i-1][0]+dp[i-1][1];
			}
			else {
				dp[i][0] = dp[i-1][0]+dp[i-1][1];
				dp[i][1] = 1;
				for(int j=i-1;j>=0;--j){
					if(pos[i]-pos[j]>=L){
						dp[i][1] = max(dp[i][1],dp[j][0]+dp[j][1]);
						break;
					}
				}
			}
			dp[i][0]%=1000000007;
			dp[i][1]%=1000000007;
		}
		//debug(cnt);
		printf("Case #%d: ",fl++);
		if(cnt==0)cout<<1<<endl;
		else {
			ll ans = (dp[cnt-1][0]+dp[cnt-1][1])%1000000007;
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
3
heabchehe
he
xxxxxxx
xxx
*/
