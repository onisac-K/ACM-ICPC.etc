#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int count=0;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int a;
		count=0;
		for(int i=0;i<3;++i){
			cin>>a;
			if(a==1)count++;
		}
		if(count>=2)ans++;
	 } 
	 cout<<ans<<endl;
	return 0;
} 
