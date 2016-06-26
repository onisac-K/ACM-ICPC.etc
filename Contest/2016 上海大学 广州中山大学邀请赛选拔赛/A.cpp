#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
	int d;
	int x;
}stu1[50005];

int sum[50005];

bool cmp(node a,node b)
{
	return a.d<b.d;
}

int main()
{
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		memset(sum,0,sizeof(sum));
		scanf("%d",&n);
		int d,x;
		char c[2];
		int s1=0,s2=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d %d %c",&d,&x,c);
			if(c[0]=='c'&&x==1)
			{
				stu1[s1].x=1;
				stu1[s1++].d=d;
				
			}
			else if(c[0]=='i'&&x==0)
			{
				stu1[s1].x=0;
				stu1[s1++].d=d;
			}
		}
		sort(stu1,stu1+s1,cmp);
		//for(int i=0;i<s1;++i)cout<<stu1[i].d<<' '<<stu1[i].x<<endl;
		int sum1=0,sum2=0;
		int fff=-1;
		for(int i=0;i<s1;++i)
		{
			if(stu1[i].x==0)
			{
				if(stu1[i].d>fff)
				{
					fff=stu1[i].d;
					sum2=0;
				}
				sum1++;
				if(stu1[i].d==fff)sum2++;
			}
			else if(stu1[i].x==1&&stu1[i].d>fff)
			{
				sum[i]=sum1;
			}
			else if(stu1[i].x==1&&stu1[i].d==fff)
			{
				sum[i]=sum1-sum2;
			}
		}
		ll ans=0;
		//for(int i=0;i<s1;++i)cout<<sum[i]<<endl;
		for(int i=0;i<s1;++i)ans+=sum[i];
		printf("%d\n",ans);
	}
}

/*
2
4
2 0 i
2 1 c
2 1 c
2 1 i
4
2 0 i
3 1 c
3 0 i
5 1 c


*/
