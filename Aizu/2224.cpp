#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

struct edge{
	int u,v;
	double d;
}ed[100005];

bool cmp(edge a,edge b){
	return a.d>b.d;
}

struct node{
	int x;
	int y;
}s[10005];

int ra[10005],pa[10005]; 
  
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

double getdis(int x,int y){
	int Y = s[x].y-s[y].y;
	int X = s[x].x-s[y].x;
	return sqrt(Y*Y*1.0 + X*X*1.0);
}

int main()
{
	int n,m;
	while(cin>>n>>m){
		init(n); 
		for(int i=1;i<=n;++i){
			scanf("%d%d",&s[i].x,&s[i].y);
		}
		int u,v;
		double d,sum = 0;
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			double dis = getdis(u,v);
			ed[i].u = u;
			ed[i].v = v;
			ed[i].d = dis;
			sum += dis;
		}
		sort(ed,ed+m,cmp);
		double ans = 0;
		for(int i=0;i<m;++i){
			u = ed[i].u;
			v = ed[i].v;
			d = ed[i].d;
			if(same(u,v))continue;
			else {
				unite(u,v);
				ans += d;
			}
		}	
		printf("%.3f\n",sum-ans);
	}
	return 0;
 } 
