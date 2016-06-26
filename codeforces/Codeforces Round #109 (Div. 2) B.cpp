#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> A,pair<int,int> B)
{
	if(A.second!=B.second)return A.second>B.second;
	else return A.first>B.first;
}

int main()
{
	int n;
	cin>>n;
	vector<pair<int,int> >v;
	int x,y;
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end(),cmp);
	//for(int i=0;i<n;++i)cout<<v[i].first<<' '<<v[i].second<<endl;
	int chance = 1;
	int point = 0;
	for(int i=0;i<n;++i)
	{
		if(chance<=0)break;
		point+=v[i].first;
		chance+=v[i].second;
		chance--; 
	}
	cout<<point<<endl;
	return 0;
}

/*
5
1 0
2 0
3 1
2 1
1 2
*/
