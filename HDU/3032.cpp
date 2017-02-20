#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
//f[]：可以取走的石子个数
//sg[]:0~n的SG函数值
//hash[]:mex{}
int s[105];
int sg[10005];
int k;

int mex(int val){
	if(sg[val]!=-1)return sg[val];
	bool vis[10005];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<val;++i){
		sg[i] = mex(i);
		vis[sg[i]] = 1;
	}
	for(int i=1;i<val;++i){
		for(int j=1;j<val;++j){		
			if(i+j == val){
				int v = mex(i)^mex(j);				
				vis[v] = 1;			
			}
		}
	}
	/*for(int i=0;i<k;++i){
		int v = val - s[i];
		if(v>=0){
			sg[v] = mex(v);
			vis[sg[v]] = 1;
		}
		else break;
	}*/
	for(int i=0;;++i){
		if(vis[i] == false){
			return sg[val]=i;
		}
	}
}

int a[1000005];

int main()
{
	/*memset(sg,-1,sizeof(sg));
	sg[0] = 0;
	for(int i=0;i<=100;++i)if(i!=mex(i))cout<<i<<' '<<mex(i)<<endl;*/
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans = 0;
		long long x;
		while(n--){
			scanf("%lld",&x);
			if(x%4 == 3)x++;
			else if(x%4 == 0)x--;
			ans ^= x; 
		}
		if(ans != 0)cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}

	return 0;
}
