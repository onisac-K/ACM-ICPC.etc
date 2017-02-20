#include <stdio.h>  
int main()  
{  
    int z,n,k;  
    scanf("%d",&z);  
    while(z--)  
    {  
        scanf("%d%d",&n,&k);  
        if(k&1)  
            puts(n&1?"1":"0");  
        else  
        {  
            n = n%(k+1);  
            if(n == k)  
                printf("%d\n",k);  
            else  
                puts(n&1?"1":"0");  
        }  
    }  
    return 0;  
}  
