#include<bits/stdc++.h>
using namespace std;

int a[105]={0};

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		int t;
		cin>>t;
		for(int j=0;j<t;++j)
		{
			int x;
			cin>>x;
			a[x]=1;
		}
	}
	int flag=0;
		for(int i=1;i<=m;++i)if(a[i]==0){
			flag=1;
			break;
		}
		if(flag==1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	return 0;
}
