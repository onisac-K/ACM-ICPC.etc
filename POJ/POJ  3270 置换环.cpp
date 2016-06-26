#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[10005];
int b[10005];
int flag[10005];
int c[100005];

int main()
{
	int n;
	cin>>n;
	memset(flag,0,sizeof(flag));
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b,b+n);
	for(int i=0;i<n;++i)
	{
		c[a[i]]=i;
	}	
	int ans=0;
	for(int i=0;i<n;++i)
	{
		if(flag[i]==0)
		{
			int sum=0,f=a[i],Min=100005,len=0,j=i;
			while(1)
			{
				len++;
				sum+=f;
				//cout<<f<<' '<<b[j]<<endl;
				if(f<Min)Min=f;
				j=c[b[j]];
				f=a[j];				
				flag[j]=1;				
				if(f==a[i])break;
			}
		//	cout<<sum<<' '<<Min<<' '<<len<<endl;
			ans+=min(sum+(len-2)*Min,sum+Min+(len+1)*b[0]);
		}
		
	}
	cout<<ans<<endl;
	return 0;
} 
/*
6
8 4 5 3 2 7
*/
