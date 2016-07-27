#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[105][105];
struct edge{
	int u,v,d;
}ed[100005];

bool cmp(edge a,edge b){
	return a.d<b.d;
}

int ra[105],pa[105]; 
  
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
	int n;
	while(cin>>n){
		init(n); 
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&a[i][j]);
				ed[i*n+j].u = i;
				ed[i*n+j].v = j;
				ed[i*n+j].d = a[i][j];
			}
		}
		sort(ed,ed+n*n,cmp);
		int ans = 0;
		for(int i=0;i<n*n;++i){
			int u = ed[i].u;
			int v = ed[i].v;
			int d = ed[i].d;
			if(same(u,v))continue;
			else {
				unite(u,v);
				ans += d;
			}
		}	
		cout<<ans<<endl;
	}
	return 0;
 } 
