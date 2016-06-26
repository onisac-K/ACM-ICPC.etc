#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0;
	int x[10];
	for(int i=0;i<10;++i)
	{
		scanf("%d",&x[i]);
	}
	int h;
	cin>>h;
	h+=30;
	for(int i=0;i<10;++i)
	{
		if(x[i]<=h)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
