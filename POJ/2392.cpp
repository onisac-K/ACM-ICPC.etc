#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[40005];
struct node{
	int h;
	int a;
	int c;
}s[505];

bool cmp(node a,node b)
{
	return a.a<b.a;
}

int main()
{
	int k;
	cin>>k;
	int h,a,c;
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i=0;i<k;++i){
		scanf("%d%d%d",&h,&a,&c);
		s[i].a = a;
		s[i].c = c;
		s[i].h = h;
	}
	sort(s,s+k,cmp);
	for(int q=0;q<k;++q){
		for(int i=1;i<=s[q].c;++i){
			for(int j=s[q].a;j>=s[q].h;--j){
				//cout<<j<<" "<<s[q].h<<endl;
				if(dp[j-s[q].h]==1)dp[j] = 1;
			}
		}
		//for(int i=0;i<a;++i)if(dp[i])cout<<i<<' ';cout<<endl;
	}
	int ans = 0;
	for(int i=40000;i>=0;--i){
		if(dp[i]){
			ans = i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
