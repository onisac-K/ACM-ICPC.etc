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

int ans[105];

void mul(int i)
{	
	//cout<<i<<endl;
	for(int j=0;j<101;++j)
	{
		ans[j]*=i;		
	}
	for(int j=0;j<101;++j)
	{
		int x=ans[j]/10;
		ans[j]%=10;
		ans[j+1]+=x;
	}
}


int main() {
    long long m, n, k;
    ans[0]=1;
        memset(d,0,sizeof(d));
        ans[0]=1;
        scanf("%lld%lld", &m, &n);
        n = n + m;
        k = m;
        get_pri(n, k);
        //cout<<123<<endl;
       

        for(int i=2;i<200001;i++){
            for(int j=0;j<d[i];j++){
                mul(i);
            }
        }
        //cout<<a<<endl;
       
		for(int i=99;i>=0;--i)
		{
			if(i%10==0)
			{
				cout<<ans[i]<<endl;
			}
			else cout<<ans[i];
		}
    
    return 0;
}
