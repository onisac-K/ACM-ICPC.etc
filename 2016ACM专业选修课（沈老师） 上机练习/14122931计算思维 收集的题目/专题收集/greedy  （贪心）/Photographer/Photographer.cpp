#include <iostream>  
#include<algorithm>  
#include<cstdio>  
#include <cstring>  
#include<string>  
using namespace std;  

/*
����������һ���������⣬������һ��������£�
�����ܷ������壬��֤�������������뷨��
�������С��������Ȼ�������У�Ϊ�˼�¼��
�꣬�����õ���C++���� pair������sort��pair
����ʱ��Ե��ǵ�һ��Ԫ�ء�
*/

pair<int,int> v[100100];  
int n,d,a,b,x,y,i,j;  
  
int main()  
{  
    while(cin>>n>>d>>a>>b)
    {
	    for(i=0;i<n;++i)  
	    {  
	        scanf("%d%d",&x,&y);  
	        v[i].first=x*a+b*y;  
	        v[i].second=i+1;  
	    }  
	    sort(v,v+n);  
	    for(i=0;i<n;++i)  
	    {  
	        d-=v[i].first;  
	        if(d<0)  
	        {  
	            cout<<i<<endl;  
	            break;  
	        }  
	        if(i==n-1)  
	        {  
	            cout<<n<<endl;  
	        }  
	    }  
	    for(j=0;j<i;++j)  
	    {  
	        cout<<v[j].second<<' ';  
	    }  
	    cout<<endl;  
	}
    return 0;  
}  
