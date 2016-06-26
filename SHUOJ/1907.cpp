/* n�׷��ξ��������ģ�壬���m*n�ľ�����Կ��ǽ�m��n����ṹ��matrix�� 
   ������Ϊ3�����ֱ��Ǿ�����ˣ�ת����λ���󣬿����ݡ� 
   ���Խ��  AC   
   BY SHU_ONISAC */  
#include<iostream>  
#include<cstring>  
using namespace std;  
int mod; 
struct matrix{  
    long long a[15][15];  
};  
  
matrix matrix_muti(matrix a,matrix b,int n)//������ˣ����ֻҪע��i��j��k��˳������ˣ�   
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
  
matrix init(matrix r,int n)//ת����λ����   
{  
    for(int i=0;i<n;++i){  
        for(int j=0;j<n;++j)  
           r.a[i][j]=(i==j);  
    }  
    return r;  
}  
  
matrix fast_power(matrix a,int n,int k)//������   
{   
	matrix r;  
    r=init(r,n);//�Ƚ�r.a��Ϊ��λ����   
    while(k){  
      if(k&1)r=matrix_muti(r,a,n);    
      a=matrix_muti(a,a,n);  
      k=k>>1;  
    }  
    for(int i=0;i<2;++i)//������   
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
        for(int i=0;i<2;++i)//����������ݴ���ori��   
           for(int j=0;j<2;++j)  
              cin>>ori.a[i][j];
		printf("Case %d:\n",f++);  
        fast_power(ori,2,n);//���п�����   
  
         
    }  
    return 0;  
}  
