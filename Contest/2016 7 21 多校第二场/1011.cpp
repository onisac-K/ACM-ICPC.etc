#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		int cnt = 0;
		for(int i=0;i<n;++i){
			if(a[i]%2==1){
				cnt++;
				a[i]--;
			}
		}
		int sum = 0;
		for(int i=0;i<n;++i)sum+=a[i];
		if(cnt == 0){
			cout<<sum<<endl;
			continue;
		}
		int ans = 1;
		while(sum>=0){
			
			sum -= cnt*2;
			if(sum>=0)ans+=2;
		}
		
		cout<<ans<<endl;
	} 
	return 0;
} 
