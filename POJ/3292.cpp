#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long

const int maxn = 1000001;
ll HP[1000005];
ll sum[1000005];

void init()
{
	memset(sum,0,sizeof(sum));
	memset(HP,0,sizeof(HP));
	
	for(int i=5;i<=maxn;i+=4){
		for(int j=5;j<=maxn;j+=4){
			if(i*j>maxn)break;
			if(HP[i]==0 && HP[j]==0){
				HP[i*j]=1;
			}
			else HP[i*j]=-1;
		}
	}
	for(int i=1;i<=maxn;++i)sum[i]=sum[i-1]+(HP[i]==1);
}


int main()
{
	int n;
	init();
	while(cin>>n && n){
		cout<<n<<' '<<sum[n]<<endl;
	}
	return 0;
}

