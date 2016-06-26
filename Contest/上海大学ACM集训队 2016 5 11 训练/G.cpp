#include<bits/stdc++.h>
using namespace std;

int a[105];
int dp[105];
int f[105];
int n,m;
int main()
{
	
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<i;++j)
			{
				//if(i==3)cout<<a[2]<<' '<<a[i]<<' '<<dp[i]<<endl;
				if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1);
			}
		}
		//for(int i=1;i<=n;++i)cout<<dp[i]<<' ';
		//cout<<endl;
		for(int i=n;i>=1;--i)
		{
			for(int j=n+1;j>i;--j)
			{
				if(a[j]<a[i])f[i]=max(f[i],f[j]+1);
			}
		}
		int ans=5000;
		for(int i=1;i<=n;++i)ans=min(ans,n-(dp[i]+f[i]));
		cout<<ans+1<<endl;
		/*for(int i=0;i<n;++i)scanf("%d",&a[i]);
		sort(a,a+n);
		queue<int>q;
		for(int i=0;i<n;++i)q.push(a[i]);
		int x,y;
		x=q.front();
		q.pop();
		y=q.front();
		q.pop();
		int ans=0;
		cout<<x<<' '<<y<<endl;
		while(!q.empty())
		{
			while(1&&!q.empty())
			{
				int xx=q.front();
				q.pop();
				if(xx>y)
				{
					cout<<xx<<endl;
					x=xx;
					break;
				}
				else if(x>x)
				{
					cout<<xx<<endl;
					x=xx;
					break;
				}
				else ans++;	
			}
			while(1&&!q.empty())
			{
				int xx=q.front();
				q.pop();
				if(xx>y)
				{
					cout<<xx<<endl<<endl;
					
					y=xx;
					break;
				}
				else ans++;	
			}			
		}
		cout<<ans<<endl;*/
	}
	return 0;
}
