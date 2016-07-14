#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define ll long long 

ll dp1[1110],dp2[1110];

int main ()
{
	int n,m;
	cin>>n>>m;
	dp1[0]=1;
	ll inf = 1000000000000000000;
	for(int i=1;i<=m;++i){
		for(int j=0;j<=n;++j){
			dp2[j+i]=dp2[j+i]+dp2[j]+(dp1[j+i]+dp1[j])/inf;
			dp1[j+i]=(dp1[j+i]+dp1[j])%inf;
		}	
	}
	if(dp2[n])cout<<dp2[n];
	cout<<dp1[n]<<endl;
	return 0;
}
