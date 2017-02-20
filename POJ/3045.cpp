#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct node{
	int w,s;
	bool operator< (const node & c)const{
		return w+s<c.w+c.s;
	}
}s[50005];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		scanf("%d%d",&s[i].w,&s[i].s);
	}
	sort(s,s+n);
	long long ans = 0-s[0].s;
	long long sum = s[0].w;
	for(int i=1;i<n;++i){	
		ans = max(ans,sum - s[i].s);
		sum += s[i].w;
	}
	cout<<ans<<endl;
	return 0;
}

 
