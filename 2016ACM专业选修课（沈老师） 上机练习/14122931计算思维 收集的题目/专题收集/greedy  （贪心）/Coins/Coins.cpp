#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <cstring>  
#include <string>  
#include<set>  
#include <algorithm>  
using namespace std;  

/*
题目的意思翻译过来是给定数，求出一组数列，
其中每个数都能被该组数列中后面的数字整除。
首先用循环找到第一个数的最大因子，然后以这个
因子为起点继续向下找，不断迭代进行下去，直到1为止。
*/ 

int main()  
{  
    int n,i;  
    while(scanf("%d",&n)!=EOF)
    {
    	for(i=n;i>=1;i--)  
	    {  
	        if(n%i==0)  
	        {  
	            printf("%d ",i);  
	            n=i;  
	        }  
	    }  
   	 	printf("\n");  
	}
    return 0;
}  
  
