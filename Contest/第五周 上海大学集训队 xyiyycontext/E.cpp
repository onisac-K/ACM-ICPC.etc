/*unfinished*/

#include<bits/stdc++.h>
using namespace std;
int a[200],b[200];
int dp[100000100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,e;
		cin>>n;
		int aa;
		priority_queue<int,vector<int>,greater<int> >q;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&aa);
			q.push(aa);
		}
		int x,y;
		for(int i=0;i<n;++i)
		{
			x=q.top();
			q.pop();
			y=q.top();
			q.pop();
			a[i]=min(x,y);
			b[i]=x+y-a[i];
			if(q.empty())
			{
				a[i+1]=0;
				b[i+1]=x+y;
				break;
			}
			q.push(x+y);
		}
		for(int i=0;i<=n;++i)cout<<a[i]<<' '<<b[i]<<endl;
	}
	return 0;
}
