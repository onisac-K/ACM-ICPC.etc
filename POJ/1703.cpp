#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100005;
int ra[N*2],pa[N*2];   
  
void init(int n)  
{  
    for(int i=0;i<=n;++i)  
    {  
        ra[i]=0;  
        pa[i]=i;  
    }  
}  
  
int find(int x)  
{  
    if(x!=pa[x])pa[x]=find(pa[x]);  
    return pa[x];  
}  
  
void unite(int x,int y)  
{  
    x=find(x);  
    y=find(y);  
    if(x==y)return;  
    if(ra[x]>ra[y])  
    {  
        pa[y]=x;  
    }  
    else   
    {  
        pa[x]=y;  
        if(ra[x]==ra[y])ra[y]++;  
    }  
    return ;  
}  
  
bool same(int x,int y)  
{  
    x=find(x);  
    y=find(y);  
    if(x==y)return 1;  
    else return 0;  
}  

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		init(2*n);
		char s[2];
		int a,b;
		for(int i=0;i<m;++i){
			scanf("%s%d%d",s,&a,&b);
			//cout<<a<<b<<endl;
			if(s[0]=='A'){
				if(same(a,b+n)){
					printf("In different gangs.\n");
				}
				else if(same(a,b)){
					printf("In the same gang.\n");
				}
				else printf("Not sure yet.\n");
			}
			if(s[0]=='D'){
				unite(a,b+n);
				unite(a+n,b);
			}
		}
	}
	return 0;
 } 
