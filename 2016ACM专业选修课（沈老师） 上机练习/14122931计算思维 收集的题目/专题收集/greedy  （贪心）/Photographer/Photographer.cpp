#include <iostream>  
#include<algorithm>  
#include<cstdio>  
#include <cstring>  
#include<string>  
using namespace std;  

/*
此题类似于一个背包问题，在容量一定的情况下，
尽可能放入物体，保证放入的总数最大。想法是
对物体从小到大排序，然后放入进行，为了记录下
标，这里用到了C++里面 pair容器，sort对pair
排序时针对的是第一个元素。
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
