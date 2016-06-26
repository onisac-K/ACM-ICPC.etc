#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
	int a;
	int b;
	int value;
}point[1005];

bool cmp(node a,node b)
{
	return a.value<b.value;
}

int ra[1005],pa[1005];  
int flag[1005];  
  
void init(int n)  
{  
    for(int i=0;i<=n;++i)  
    {  
        ra[i]=0;  
        pa[i]=i;  
        flag[i]=0;  
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
	while(cin>>n&&n)
	{
		init(n);
		int k=0;
		for(int i=0;i<n-1;++i)
		{
			char a[2],b[2];
			int na,nb;
			scanf("%s %d",a,&na);
			for(int j=0;j<na;++j)
			{
				scanf("%s %d",b,&nb);
				point[k].a=a[0]-'A';
				point[k].b=b[0]-'A';
				point[k++].value=nb;
			}
		}
		sort(point,point+k,cmp);
		int ans=0;
		ans+=point[0].value;
		unite(point[0].a,point[0].b);
		for(int i=1;i<k;++i)
		{
			if(same(point[i].a,point[i].b))continue;
			ans+=point[i].value;
			unite(point[i].a,point[i].b);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
