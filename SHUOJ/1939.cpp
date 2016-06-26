#include <bits/stdc++.h>
using namespace std;
int d[500001]={};
void get_pri(int n, int k) {
    int i, j,cnt=0,z=k,f=n;
    while (k--) {
        n=f-k;
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0){
                    n = n / i;
                    d[i]++;
                }
            }
        }
        if(n!=1)
        d[n]++;
    }
    while(z--){
        int dd=z+1;
        for (i = 2; i * i <= dd; i++) {
            if (dd % i == 0) {
                while (dd % i == 0){
                   dd = dd / i;
                    d[i]--;
                }
            }
        }
        if(dd!=1)
        d[dd]--;
    }
}




int main() {
    long long m, n, K;	
	int t;
	cin>>t;	
    while(t--)
    {
	  	scanf("%lld%lld%lld", &n, &m , &K);
	  	memset(d,0,sizeof(d));
        get_pri(n, m);//4 2
        //cout<<123<<endl;
       
       	long long ans=1;
		//cout<<K<<endl;
        for(int i=2;i<200001;i++){
            for(int j=0;j<d[i];j++){
            	//cout<<i<<endl;
                ans*=i;
                //cout<<ans<<endl;
                ans%=K;
            }
        }
    
	    cout<<ans<<endl;
 	}
		
    
    return 0;
}
