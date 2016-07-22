#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

bool prime[10000005];
int p[700000];
int k;
int Max;
int Len;

void init()
{
	prime[0]=1;
	prime[1]=1;
	k=0;
	for(int i=2;i<=2000000;++i){
		if(prime[i]==0){
			p[k++]=i;			
			for(int j=i+i;j<=2000000;j+=i){
				prime[j]=1;
			}
		}
	}
}

int num[25];

int main()
{
	int n;
	init();
	while(scanf("%d",&n)!=EOF){
		int L = 0;
		int Len = 0;
		int cnt = 0;
		long long ans = 1;
		int N = n;
		for(int i=0;i<k;++i){
			//if(p[i]>N/2)break;
			L = 0;
			int flag = 1;
			while(n%p[i]==0){
				//cout<<n<<' '<<p[i]<<endl;
				L++;
				flag = 0;
				n/=p[i];
			}	
			if(flag == 0)num[cnt++]=L;
			Len += L;
			if(n==1)break;	
		}
		//cout<<Len<<endl;
		for(int i=1;i<=Len;++i)ans *= i;
		for(int i=0;i<cnt;++i){
			for(int j=2;j<=num[i];++j)ans/=j;
		}
		cout<<Len<<' '<<ans<<endl;
	}
	return 0;
}
