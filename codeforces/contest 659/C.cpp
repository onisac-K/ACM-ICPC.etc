#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	set<int>s;
	int x;
	for(int i=0;i<n;++i)
	{
		cin>>x;
		if(!s.count(x))s.insert(x);
	}
	vector<int>ans;
	for(int i=1;;++i)
	{
		if(s.count(i))continue;
		if(m>=i)
		{
			ans.push_back(i);
			m-=i;
		}
		else break;
		
	}
	int l=ans.size();
	cout<<l<<endl;
	for(int i=0;i<l;++i)
	{
		if(i<l-1)cout<<ans[i]<<' ';
		else cout<<ans[i]<<endl;
	}
	return 0;
}
