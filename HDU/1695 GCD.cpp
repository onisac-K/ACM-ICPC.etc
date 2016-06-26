#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Max 100005
#define N 100005

int mu[100005];
int vis[100005];
int prime[N];

void Mobius(){          
    memset(vis,0,sizeof(vis));            
    mu[1] = 1; 
	int cnt = 0; 
    for(int i=2; i<N; i++) { 
        if(!vis[i]) {                     
            prime[cnt++] = i;   mu[i] = -1; 
        } 
        for(int j=0; j<cnt&&i*prime[j]<N; j++) { 
            vis[i*prime[j]] = 1;    
            if(i%prime[j]) mu[i*prime[j]] = -mu[i]; 
            else { 
                mu[i*prime[j]] = 0; break;  
            } 
       } 
    } 
} 


int main()
{
	int t;
	
	cin>>t;
	Mobius();
	int a,b,c,d,k;
	int f=0;
	while(t--)
	{
		cin>>a>>b>>c>>d>>k;
		printf("Case %d: ",++f);
		if(k==0)
		{
			cout<<0<<endl;
			continue;
		}
		b/=k;
		d/=k;
		int n=min(b,d);
		int m=b+d-n;
		ll ans1=0;
		ll ans2=0;
		for(int i=1;i<=n;++i)ans1+=1LL*mu[i]*(n/i)*(m/i);
		for(int i=1;i<=n;++i)ans2+=1LL*mu[i]*(n/i)*(n/i);
		ans1-=ans2/2;
		cout<<ans1<<endl;
		//cout<<ans1<<endl;
	}
}
