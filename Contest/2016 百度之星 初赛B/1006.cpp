#include<iostream>
#include<cstdio> 
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<stack>
#include<map>
using namespace std;
#define ll long long 

ll a[5005];
int b[5005];
int dp[5005];

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;++i)
        {
        	int ans = 0; 
        	int a1 = 0,a2 = 0;
            for(int j=1;j<=n;++j)
            {
            	if(i==j)continue;
            	if(a[i]>a[j])a1++;
            	if(a[i]<a[j])a2++;
			} 
			ans = min(a1,a2);
			b[i]=ans+1;
        }
        for(int i=1;i<=n;++i)
        {
            if(i<n)printf("%d ",b[i]);
            else printf("%d\n",b[i]);
        }
    }
    return 0;
}
