#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
ll b[100005];
int main()
{
	int n;
	//freopen("1935.in","r",stdin);
	//freopen("a.txt","w",stdout);
	
	while(cin>>n){
		for(int i=1;i<=n;++i){
			scanf("%lld",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		ll ans = 0;
		for(int i=n;i>=1;--i){
			ll s = i-(lower_bound(b+1,b+1+n,a[i])-b);
			ans = max(ans,s);
		}
		cout<<ans<<endl;
	}
	return 0; 
} 
 
