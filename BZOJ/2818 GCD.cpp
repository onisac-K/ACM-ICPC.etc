#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Max 10000005

int euler[Max];
bool prime[10000005];
int p[700000];
ll sum[10000005];

void init(int n){ 
    	euler[1]=1;
     	for(int i=2;i<=n;i++)
     	euler[i]=i;
    	for(int i=2;i<=n;i++)
        	if(euler[i]==i)
           	for(int j=i;j<=n;j+=i)
            euler[j]=euler[j]/i*(i-1);//先进行除法是为了防止中间数据的溢出 
}


int main()
{
	int n;
	scanf("%d",&n);
	prime[0]=1;
	prime[1]=1;
	int k=0;
	init(n);
	//cout<<euler[2]<<endl;
	for(int i=2;i<=n;++i)
	{
		if(prime[i]==0)
		{	
			p[k++]=i;		
			for(int j=i+i;j<=n;j+=i)	
			{
				prime[j]=1;
				//cout<<j<<endl;
			}
		}
	}
	
	ll ans=0;
	//for(int i=0;i<100;++i)cout<<p[i]<<endl;
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+euler[i];
	for(int i=0;i<k&&p[i]<=n;++i)
	{
		//cout<<euler[n/p[i]]<<endl;
		ans+=sum[n/p[i]]*2-1;			
	}
	printf("%lld",ans);
	return 0;
}
/*9999991*/ 
