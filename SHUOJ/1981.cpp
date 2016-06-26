#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t ;
    scanf("%d",&t);
    while(t--)
    {
        ll n,m;
        scanf("%lld%lld",&n,&m);        
        ll x=m;
        ll ans=0;
        ll k=n/m;
        k=(((k+1)*k)/2)*m-k;
        k/=2;
        cout<<k<<endl;
        if(m%2==0)k-=((n/m)/2);
        else k-=((n/m)/2/2);
        cout<<k<<endl;
        ans+=k; 
        k=(n/m+1);
        ll k2=(n-1)*2/m;
        while(k2*m/2+1<=n)k2++;
        while(k2*m/2+1>n)k2--;
        k2-=n/m;
        if(k2!=0)ans+=n*k2-((k+k+k2-1)*k2/2*m)/2;
        if(m%2!=0)
        {
            ll num=k2/2;
            if(k*m%2==1&&k2>2&&k2%2!=0)num++;
            ans+=num/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
} 
