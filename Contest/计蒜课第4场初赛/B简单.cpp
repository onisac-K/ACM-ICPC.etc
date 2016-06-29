#include<bits/stdc++.h>
using namespace std;

int a[1000000];
int n,m;
int ans = 0;
int as[100];
void dfs(int len,int k)
{
	if(len <= n)
	{
		//for(int i=1;i<=len;++i)cout<<a[i]<<' ';
		//cout<<endl;
		int flag=0;
		for(int i=1;i<=len;++i)
		{
			int s=0;
			if(i%2==0)
			{
				for(int j=1;j<=i/2;++j)
				{
					if(a[j]!=a[i/2+j])
					{
						s=1;
						break;
					}		
				}
				if(s==0)flag=1;
			}
			if(flag==1)break;
		}
		if(flag==0)
		{
			as[len]++;
			ans++;
		}
	}
	if(len<n)
	for(int i=1;i<=m;++i)
	{
		a[len+1]=i;
		dfs(len+1,i);
		a[len+1]=0;
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		a[1]=i;
		dfs(1,i);
		a[1]=0;
	}
	for(int i=1;i<=n;++i)cout<<as[i]<<endl;
	cout<<ans<<endl;
	return 0;
} 
