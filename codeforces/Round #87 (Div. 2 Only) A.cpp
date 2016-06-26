#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0;
	int t;
	cin>>t;
	int x,y;
	int ma=0;
	for(int i=0;i<t;++i)
	{
		scanf("%d%d",&x,&y);
		ans+=y;
		ans-=x;
		ma=max(ma,ans);
	}
	cout<<ma<<endl;
 } 
