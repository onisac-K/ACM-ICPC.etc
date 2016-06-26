#include<bits/stdc++.h>
using namespace std;

int a[1005];

int main()
{
	int m,n;
	
	while(cin>>m>>n)
	{
		
		for(int i=0;i<=m;++i)a[i]=1;	
		for(int i=1;i<=n;++i)
		{
			for(int j=i;j<=m;j+=i)a[j]*=-1;
		}
		int ans=0;
		for(int i=1;i<=m;++i)
		{
			if(a[i]==-1)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
