#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000005];
int main(){
	int n;

	while(cin>>n){
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		ll cnt = 0,s = 0;
		for(int i=n;i>=1;--i){
			if(s == 0){
				if(a[i]>=0) cnt++;
				else {
					s = a[i];
				}
			}
			else if(s < 0){
				s += a[i];//cout<<s<<endl;
				if(s<0)continue;
				else {
					cnt++;
					s = 0;
				}
			}
		}
		cout<<cnt<<endl;
	}
}
