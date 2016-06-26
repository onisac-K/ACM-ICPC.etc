#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

struct point{
	int a;
	int b;
}l[25005];

bool cmp(point a,point b)
{
	return a.a<b.a;
}

int main()
{
	int n,t;
	cin>>n>>t;
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&l[i].a,&l[i].b);
	}
	l[n].a=0x7fffffff,l[n].b=0;
	sort(l,l+n+1,cmp);
	/*for(int i=0;i<=n;++i)
	{
		cout<<l[i].a<<' '<<l[i].b<<endl;
	}*/
	
		int ans=0;
		int y=0; 
		int temp=0,f=0;
		for(int i=0;i<n;++i)
		{
			if(l[i].a<=y+1)
			{
				if(l[i].b>temp)
				{
					temp=l[i].b;
					f=1;
				}
				if(f==1&&l[i+1].a>y+1)
				{
					ans++;
					f=0;
					y=temp;
				}
			}
			
		}
		//cout<<y<<endl;
		if(y<t)cout<<"-1"<<endl;
		else cout<<ans<<endl;
	
	return 0;
}  
