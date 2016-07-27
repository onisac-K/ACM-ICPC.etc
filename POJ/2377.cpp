#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct edge{
	int u,v,d;
}ed[100005];

bool cmp(edge a,edge b){
	return a.d>b.d;
}

int ra[1005],pa[1005]; 
  
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
	int n,m;
	while(cin>>n>>m){
		init(n); 
		int u,v,d;
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&u,&v,&d);
			ed[i].u = u;
			ed[i].v = v;
			ed[i].d = d;
			
		}
		sort(ed,ed+m,cmp);
		int ans = 0,cnt = 0;
		for(int i=0;i<m;++i){
			u = ed[i].u;
			v = ed[i].v;
			d = ed[i].d;
			if(same(u,v))continue;
			else {
				unite(u,v);
				ans += d;
				cnt++;
			}
		}	
		if(cnt == n-1)cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
 } 
