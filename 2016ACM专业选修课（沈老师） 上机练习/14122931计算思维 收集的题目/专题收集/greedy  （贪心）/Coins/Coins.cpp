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
��Ŀ����˼��������Ǹ����������һ�����У�
����ÿ�������ܱ����������к��������������
������ѭ���ҵ���һ������������ӣ�Ȼ�������
����Ϊ�����������ң����ϵ���������ȥ��ֱ��1Ϊֹ��
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
  
