#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll gcd(ll a,ll b){
	return b==0? a:gcd(b,a%b);
}


int main(){
	//freopen("a.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int x;
		ll s1=0,s2=0;
		for(int i=0;i<n;++i){
			scanf("%lld",&x);
			if(x<0)x*=-1;
			s1+=x*x;
			s2+=x;
		}
	
		ll up = n*s1 - s2*s2;
		ll G = gcd(up,n);
	
	    printf("%lld/%lld\n",up/G,n/G);
	}
	return 0;
}
