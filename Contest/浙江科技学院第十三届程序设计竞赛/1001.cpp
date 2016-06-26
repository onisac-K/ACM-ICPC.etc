#include<bits/stdc++.h>
using namespace std;

int a[400];
int b[400];
int main()
{
	int n;
	while(cin>>n)
	{
	
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;++i)
		{
			char q[2];
			int x,y;
			scanf("%s %d %d",q,&x,&y);
			//cout<<q[0]<<' '<<x<<' '<<y<<endl;;
			if(q[0]=='M')for(int j=x;j<=y;++j)a[j]++;
			else for(int j=x;j<=y;++j)b[j]++;
		}
		int ans=0;
		for(int i=0;i<370;++i)
		{
			int k=min(a[i],b[i]);
			ans=max(ans,k*2);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
