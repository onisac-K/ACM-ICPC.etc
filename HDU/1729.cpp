#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;


int sg[1000005];

int mex(int size,int val){
	int t = sqrt(size*1.0);
	while(t*t+t>=size)t--;
	if(t<val)return size-val;
	else return mex(t,val); 
}

int main()
{

	
	int n;
	int f = 1;
	while(cin>>n && n){
		memset(sg,-1,sizeof sg);
		int c,s;
		int ans = 0;
		for(int i=0;i<n;++i){
			scanf("%d%d",&s,&c);
			ans ^= mex(s,c);
		}
		printf("Case %d:\n",f++);
		if(ans != 0)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
