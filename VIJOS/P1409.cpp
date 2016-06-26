#include<bits/stdc++.h>
using namespace std;

int a[30005];
int vis[30005];

int main()
{
	int w,n;
	cin>>w>>n;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int ans=0;
	for(int i=n-1;i>=0;--i)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			if(a[i]+a[0]>w)
			{
				ans++;
				continue;
			}
			int r=i-1,l=0;
			while(l<r)
			{
				int mid = (l+r)/2;
				if(a[mid]+a[i]<=w)l=mid+1;
				else r=mid-1;
			}
			while(a[l]+a[i]<=w&&l<i)l++;
			int j;
			for(j=l-1;j>=0;--j)
			{
				if(vis[j]==0)
				{
					vis[j]=1;
					ans++;
					break;
				}
			}
			if(j<0)ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
