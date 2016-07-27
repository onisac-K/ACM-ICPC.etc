#include<iostream>
#include<cstdio>
#include<cstdlib> 
using namespace std;
#define ll long long

ll Pow(ll a,ll n,ll mod)      //取膜的版本
{
	ll ans=1;
	while(n)
	{
		if(n&1)
		{
			ans=ans*a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		n>>=1;
	}
	ans%=mod;
	return ans;
}

long long multi(long long a,long long b,long long mod){
    long long ret=0;
    while(b){
        if(b&1){
            ret=(ret+a)%mod;
        }
        a=a<<1;
        a=a%mod;
        b=b>>1;
    }
    return ret;
}
long long quickPow(long long a,long long b,long long mod){
    long long ret=1;
    while(b){
        if(b&1)
            ret=multi(ret,a,mod);
        a=multi(a,a,mod);
        b=b>>1;
    }
    return ret;
}
bool witness(long long a,long long n){
    long long m=n-1;
    int j=0;
    while(!(m&1)){
        j++;
        m=m>>1;
    }
    long long x=quickPow(a,m,n);
    if(x==1||x==n-1)
        return false;
    while(j--){
        x=multi(x,x,n);
        if(x==n-1)
            return false;
    }
    return true;
}

//判定n是否为素数，若是，返回true
bool Miller_Rabin(long long n){
    if(n==2)
        return true;
    if(n<2 || !(n&1))
        return false;
    for(int i=0;i<5;i++){
        long long a=rand()%(n-1)+1;
        if(witness(a,n))
            return false;
    }
    return true;
}
long long Gcd(long long a,long long b){
    return b==0?a:Gcd(b,a%b);
}



int main()
{
	int p,a;
	while(cin>>p>>a && (p||a)){
		if(Miller_Rabin(p)){
			cout<<"no"<<endl;
			continue;
		}
		else {
			int ans = Pow(a,p,p);
			if(ans == a)cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	} 
	return 0;
}

