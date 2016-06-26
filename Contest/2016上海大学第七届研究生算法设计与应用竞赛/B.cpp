#include<bits/stdc++.h>
using namespace std;

int a[1005];
int n;
void dfs()
{
	int flag=0;
	for(int i=0;i<n-1;++i)
	{
		if(a[i+1]-a[i]>=2)
		{
			int c=a[i+1];
			a[i+1]=a[i]+1;
			a[i]=c-1;
			flag=1;
		}
	}
	//cout<<flag<<endl;
	if(flag==0)return ;
	else dfs();
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{

		cin>>n;
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		int flag=0;
		dfs();

		for(int i=n-1;i>=1;--i)
		{
			if(a[i]>a[i-1])
			{
				//cout<<a[i]<<' '<<a[i-1]<<endl;
				flag=1;
				break;
			}
		}		
		if(flag==1)
		{
			printf("Impossible\n");
		}
		else 
		{
			for(int i=0;i<n-1;++i)printf("%d ",a[i]);
			printf("%d\n",a[n-1]);
		}	
	}
	return 0;
}

/*
2
11
972 968 942 937 933 897 893 793 777 774 766 
*/
