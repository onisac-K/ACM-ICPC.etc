#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char x[105];
	vector<pair<int ,int> >g[105];
	int stu[105];
	memset(stu,0,sizeof(stu));
	for(int i=0;i<n;++i)
	{
		scanf("%s",x);
		int len=strlen(x);
		for(int j=0;j<len;++j)
		{
			int y=x[j]-'0';
			g[j].push_back(make_pair(y,i));
		}
	}
//	cout<<123<<endl;
	for(int i=0;i<m;++i)
	{
		sort(g[i].begin(),g[i].end());
		pair<int,int> op=g[i][n-1];
		//cout<<op.first<<' '<<op.second<<endl;
		stu[op.second]++;
		for(int j=n-2;j>=0;--j)
		{
			pair<int,int> oo=g[i][j];
			if(oo.first==op.first)stu[oo.second]++;
		}
	}
	//cout<<123<<endl;
	//for(int i=0;i<n;++i)cout<<stu[i]<<endl;
	
	int num=0;
	for(int i=n-1;i>=0;--i)if(stu[i])num++;
	cout<<num<<endl;
}
