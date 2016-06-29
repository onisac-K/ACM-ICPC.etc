#include<bits/stdc++.h>
using namespace std;

int l[30005];
int r[30005];
int a[30005];

int main()
{
	int t;
	cin>>t;
	int f=1;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		int min=a[1];
		printf("Case %d: ",f++);
		for(int i=1;i<=n;++i)
		{
			int j = i-1;
			l[i]=1;
			while(a[j]>=a[i]&&j>=0)
			{
				l[i]=l[i]+l[j];
				j=j-l[j];
			}
		}
		for(int i=n;i>=0;--i)
		{
			int j = i+1;
			r[i]=1;
			while(a[j]>=a[i]&&j<=n)
			{
				r[i]=r[i]+r[j];
				j=j+r[j];
			}
		}
		int ans = 0;
		for(int i=1;i<=n;++i)
		{
			ans = max(ans,(l[i]+r[i]-1)*a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
