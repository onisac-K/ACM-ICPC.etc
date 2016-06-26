#include<bits/stdc++.h>
using namespace std;

int a[105];
int vis[105];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			for(int k=j+1;k<=n;++k)
			{
				if(a[k]==a[i]+a[j]&&vis[k]==0)
				{
					//cout<<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
					ans++;
					vis[k]=1;
				}
			}
		}
	}
	cout<<ans<<endl;
}
