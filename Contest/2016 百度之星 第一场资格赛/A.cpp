#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
const int mod = 9973; 
char a[100005];
int h[100005];

int mod_reverse(int a,  int m){
        int y=0,x=1,r=a%m, q, t, mm=m;//3?и║??бе
        if(r<0)r=r+m;
        while((m%r) != 0) {
            a=m; m=r;
            q= a/m; r=a % m;
            t=x; x=y-x*q; y=t;
        }
        if(r!=1) return 0;
        if(x<0) x=x+mm;
        return x;
}

int main()
{
    int n;
    while(cin>>n)
    {
        //memset(h,0,sizeof(h));
        scanf("%s",a);
        int L =strlen(a);
        //h[0]=((int)a[0]-28)%9973;
        //cout<<h[0]<<endl; 
        h[0]=1;
        for(int i=1;i<=L;++i)
        {
            h[i]=(h[i-1]*(a[i-1]-28))%9973;
        } 
        int a,b;
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&a,&b);
            //cout<<h[a]<<' '<<(mod_reverse(h[a],mod))<<endl;
            int ans = h[b]*(mod_reverse(h[a-1],9973));
            ans%=9973;
            printf("%d\n",ans);
        }
    }
}
