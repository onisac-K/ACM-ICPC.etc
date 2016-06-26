#include<iostream>  
#include<cstdio>  
#include<algorithm>  
using namespace std;  
int speed[1010];  
  
int main()  
{  
    int Ncase;  
    scanf("%d", &Ncase);  
    while(Ncase--)  
    {  
        int n, sum = 0;  
        scanf("%d", &n);  
        for(int i = 0; i < n; i++)  
            scanf("%d", &speed[i]);  
        sort(speed, speed + n); 
        while(n)  
        {  
            if(n == 1)  
            {  
                sum += speed[0];  
                break;  
            }  
            else if(n == 2)  
            {  
                sum += speed[1];  
                break;  
            }  
            else if(n == 3)  
            {  
                sum += speed[0] + speed[1] + speed[2];  
                break;  
            }  
            else if(n == 4)  
            {  
                if(speed[2] + speed[0] - 2 * speed[1] <= 0)  
                    sum += (2 * speed [0] + speed[1] + speed[2] + speed[3]);  
                else  
                    sum += (speed[0] + 3 * speed[1] + speed[3]);  
                break;  
            }  
            else  
            {  
                if(speed[n - 2] - 2 * speed[1] + speed[0] <= 0)  
                    sum += (speed[n - 1] + speed[n - 2] + 2 * speed[0]);  
                else  
                    sum += (speed[n - 1] + 2 * speed[1] + speed[0]);  
                n -= 2;  
            }  
        }  
        printf("%d\n", sum);  
    }  
    return 0;  
}                 
