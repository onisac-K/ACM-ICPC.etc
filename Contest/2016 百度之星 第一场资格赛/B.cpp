#include<iostream>  
#include<stdio.h>  
#include<string.h>  
#define maxe 1004  
using namespace std;  
int a[1005][1005];  
  
int main()  
{  
    int p;  
    //scanf("%d",&t);  
    int i,j;  
    memset(a,0,sizeof(a));  
    a[1][1]=1;  
    a[2][1]=1;  
    int s;  
    int plus=0;  
    for(i=1;i<=997;i++)  
    {  
       for(j=1;j<=maxe;j++)  
       {  
          s=a[i+1][j]+a[i][j]+plus;  
          a[i+2][j]=s%10;  
          plus=s/10;  
          //if(plus==0 && s==0)break;之所以去掉是因为存在这种情况而不能跳出的情况，  
          //例如10+10=20，如果按照这种算法就   
       }  
    }  
    while(cin>>p)  
    {  
         p++;
       for(i=maxe;i>=1;i--) if(a[p][i])break;  
       for(;i>=1;i--)  
          printf("%d",a[p][i]);  
       printf("\n");  
    }  
    return 0;  
}  
