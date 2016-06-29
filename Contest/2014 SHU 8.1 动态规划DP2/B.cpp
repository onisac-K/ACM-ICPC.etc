#include<queue>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	ll x;
	priority_queue<ll,vector<ll>,greater<ll> >q;
	for(int i=0;i<n;++i)
	{
		scanf("%lld",&x);
		q.push(x);
	}
	ll ans = 0;
	if(n==1)
	{
		ans = q.top();
		cout<<ans<<endl;
		return 0;
	}
	while(!q.empty())
	{
		ll t1=q.top();
		q.pop();
		if(q.empty())
		{
			break;
		}
		ll t2=q.top();
		q.pop();
		q.push(t1+t2);
		ans += (t1+t2);
	}
	cout<<ans<<endl;
}
