#include<bits/stdc++.h>
using namespace std;
#define lowbit(i) i&(-i)

int a[50005];
int n;

void add(int x,int num)
{
	while(x<=n)
	{
		a[x]+=num;
		x+=lowbit(x);
	}
} 

int S(int x)
{
	int s=0;
	while(x>0)
	{
		s+=a[x];
		x-=lowbit(x);
	}
	return s;
}

int main()
{
	int t;
	cin>>t;
	int f=1;
	while(t--)
	{
		
		memset(a,0,sizeof(a));
		cin>>n;
		int x;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&x);
			add(i+1,x);
		}
		//for(int i=1;i<=n;++i)cout<<a[i]<<endl;
		printf("Case %d:\n",f++);
		string s;
		int a,b;
		while(cin>>s&&s!="End")
		{
			scanf("%d%d",&a,&b);
			if(s=="Query")
			{
				printf("%d\n",S(b)-S(a-1));
			}
			else if(s=="Sub")
			{
				add(a,-b);
			}
			else add(a,b);
		}
	} 
}
