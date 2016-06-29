#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double a[3010],c[3010],d[3010];
int main()
{
    int n;
    while(cin>>n){
        cin>>a[0]>>a[n+1];
        for(int i=1;i<=n;i++){
            cin>>c[i];
        }
        double sum=0;
        for(int i=1;i<=n+1;i++){
            d[i]=d[i-1]+c[i-1]*2;
            sum+=d[i];
        }
        double ans=(a[n+1]-sum+n*a[0])/(n+1);
        printf("%.2lf\n",ans);
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
    }
    return 0; 
}
