/* n阶方形矩阵快速幂模板，如果m*n的矩阵可以考虑将m，n存入结构体matrix中 
   函数分为3个，分别是矩阵相乘，转化单位矩阵，快速幂。 
   测试结果  AC   
   BY SHU_ONISAC */  
#include<iostream>  
#include<cstring>  
using namespace std;  
int mod; 
struct matrix{  
    long long a[15][15];  
};  
  
matrix matrix_muti(matrix a,matrix b,int n)//矩阵相乘（这个只要注意i，j，k的顺序就行了）   
{  
    matrix c;  
    memset(c.a,0,sizeof(c.a));  
    for(int i=0;i<n;++i)  
       for(int j=0;j<n;++j)  
          for(int k=0;k<n;++k){  
            c.a[i][j]+=a.a[i][k]*b.a[k][j]; 
			c.a[i][j]%=mod;
          }  
    return c;  
}  
  
matrix init(matrix r,int n)//转化单位矩阵   
{  
    for(int i=0;i<n;++i){  
        for(int j=0;j<n;++j)  
           r.a[i][j]=(i==j);  
    }  
    return r;  
}  
  
matrix fast_power(matrix a,int n,int k)//快速幂   
{   
	matrix r;  
    r=init(r,n);//先将r.a化为单位矩阵   
    while(k){  
      if(k&1)r=matrix_muti(r,a,n);    
      a=matrix_muti(a,a,n);  
      k=k>>1;  
    }  
    for(int i=0;i<2;++i)//输出结果   
    {  
        for(int j=0;j<2;++j)  
        { 
			if(j<n-1)cout<<(r.a[i][j]%mod+mod)%mod<<' ';  
            else cout<<(r.a[i][j]%mod+mod)%mod;  
        }  
        cout<<endl;  
    }  
	return r;
}  
  
int main()  
{    
    matrix ori,ans;  
    int t;
    int n;
    cin>>t;
    int f=1;
    while(t--)  
    {         
    	scanf("%d%d",&n,&mod);
        for(int i=0;i<2;++i)//将输入的数据存在ori中   
           for(int j=0;j<2;++j)  
              cin>>ori.a[i][j];
		printf("Case %d:\n",f++);  
        fast_power(ori,2,n);//运行快速幂   
  
         
    }  
    return 0;  
}  
