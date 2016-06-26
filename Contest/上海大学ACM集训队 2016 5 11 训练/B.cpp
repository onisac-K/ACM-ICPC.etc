#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x;
	while(cin>>n)
	{
		priority_queue<int,vector<int>,greater<int> > q;
		for(int i=0;i<n;++i)
		{
			cin>>x;
			q.push(x);
		}
		//cout<<q.size()<<endl;
		int ans=0;
		while(q.size())
		{
			int a=q.top();
			q.pop();
			if(q.size()==0)
			{
				break;
			}
			int b=q.top();
			q.pop();
			q.push(a+b);
			ans+=(a+b);
			//cout<<a<<' '<<b<<' '<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;	
} 
