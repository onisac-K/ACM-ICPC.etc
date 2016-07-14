#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct node{
	int st,ed;
	int val;
	bool operator <(const node &b)const
	{
		if(st!=b.st)return st<b.st;
		else return ed<b.ed;
	}
}a[1005];

int dp[1005];

int main()
{
	int n,m,r;
	cin>>n>>m>>r;
	int k=0;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a[i].st,&a[i].ed,&a[i].val);
	}
	memset(dp,0,sizeof(dp));
	sort(a+1,a+1+m);
	for(int i=1;i<=m;++i){
		int ed = a[i].ed;
		int st = a[i].st;
		int val = a[i].val;
		//cout<<st<<' '<<ed<<endl;
		dp[i]=a[i].val;
		for(int j=1;j<i;++j)
			if(a[i].st-a[j].ed>=r)dp[i]=max(dp[i],dp[j]+a[i].val);
		//for(int i=1;i<=m;++i)cout<<dp[i]<<' ';
		//cout<<endl;
	}
	int ans = 0;
	for(int i=1;i<=m;++i)ans = max(ans,dp[i]);
	cout<<ans<<endl; 
	
	return 0;
}
