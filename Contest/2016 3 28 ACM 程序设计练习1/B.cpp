#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    ll a[50];
    while(t--)
    {
        int m;
        cin>>m;
        for(int i=0;i<m;++i)cin>>a[i];
        ll ans=a[0];
        for(int i=1;i<m;++i)
        {
            ll k=__gcd(ans,a[i]);
            //cout<<k<<endl;
            if(k==1)ans=ans*a[i];
            else ans=ans*a[i]/k;
            //cout<<k<<' '<<ans<<endl;
        }
        cout<<ans<<endl;
    }
}
