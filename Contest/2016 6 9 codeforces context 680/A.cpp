#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int a[105];
int main()
{
	int x;
	int sum = 0;
	memset(a,0,sizeof(a));
	for(int i=0;i<5;++i)
	{
		cin>>x;
		sum+=x;
		a[x]++;
	}
	int ans = sum;
	//cout<<sum<<endl;
	for(int i=0;i<105;++i)
	{
		if(a[i]>=2)
		{
			//cout<<i<<endl;
			if(a[i]==2)ans = min(ans,sum-i*2);
			if(a[i]>=3)ans = min(ans,sum-i*3);
		}
	}
	cout<<ans<<endl;
	
	return 0;
} 
