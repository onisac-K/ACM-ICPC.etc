#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
	int mu[N],prime[N],vis[N];
	void Mobius() {          
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
	int f=1;
	Mobius();
	while(t--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		printf("Case %d: ",f++);
		if(k==0){
			cout<<0<<endl;
			continue;
		}
		b/=k;
		d/=k;
		int x=min(b,d);
		int y=max(b,d);
		ll  ans1=0,ans2=0;
		for(int i=1;i<=x;++i)ans1+=(1LL)*mu[i]*(x/i)*(y/i);
		for(int i=1;i<=x;++i)ans2+=(1LL)*mu[i]*(x/i)*(x/i);
		ans1-=ans2/2;
		//printf("Case %d: ",f++);
		cout<<ans1<<endl;
		
	 } 
}
