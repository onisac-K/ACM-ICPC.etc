#include<stdio.h>
int main(){
    double i,n,m,s1,s2,s3,x;
    while(scanf("%lf%lf",&m,&n)!=EOF){
    s1=1;s2=1;s3=1;x=1;
        for(i=1;i<n;i++)s1=s1*i;
        for(i=1;i<=m;i++)s2=s2*i;
        for(i=1;i<=n-m;i++)s3=s3*i;
        x=s1*s2*(s1*n/(s3*s2));
        printf("%.0f\n",x);
         
         
         
        }
 
     
    return 0;}
