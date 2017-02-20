#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;

int fib[105];
int sg[10005];

int mex(int val){
	if(sg[val]!=-1)return sg[val];
	bool vis[10005];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<15;++i){
		if(val-fib[i]>=0){
			vis[mex(val-fib[i])] = 1;
		}
		else break;
	}
	for(int i=0;;++i){
		if(vis[i] == false){
			return sg[val]=i;
		}
	}
}

int a[1000005];

int main()
{
	fib[0] = 1;
	fib[1] = 2;
	// 15
	for(int i=2;;++i){
		fib[i] = fib[i-1]+fib[i-2];
		if(fib[i]>1000)break;
	}
	//cout<<fib[15]<<endl;
	int m,n,p;
	memset(sg,-1,sizeof sg);
	while(cin>>m>>n>>p && (m||n||p)){
		int ans = 0;
		ans ^= mex(m)^mex(n)^mex(p);
		if(ans != 0)printf("Fibo\n");
		else printf("Nacci\n");
	}
	return 0;
}
