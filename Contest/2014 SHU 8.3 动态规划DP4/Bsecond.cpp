#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char str[105*2];
int a[105*2];
int d1[105*2][105*2],d2[105*2][105*2];
#define INF 0x3f3f
int main()
{
	int n;
	while(cin>>n)
	{
	
		for(int i=1;i<=n;++i)
		{
			char c;
			getchar();
			scanf("%c %d",&str[i],&a[i]);
		}
		for(int i=1;i<n;++i)
		{
			str[i+n]=str[i];
			//cout<<str[i]<<endl;
			a[i+n]=a[i];
		}
		memset(d1,-INF,sizeof(d1));
		memset(d2,INF,sizeof(d2));
		for(int i=1;i<2*n;i++)
		{
			d1[i][i]=a[i];
			d2[i][i]=a[i];
		}
		for(int i=2;i<2*n;++i)
		{
			for(int j=i-1;j>=1;--j)
			{
				for(int k=j;k<i;++k)
				{
					
					if(str[k+1]=='t')
					{
						d1[j][i]=max(d1[j][i],d1[j][k]+d1[k+1][i]);
						d2[j][i]=min(d2[j][i],d2[j][k]+d2[k+1][i]);
					}
					else 
					{
						d1[j][i]=max(d1[j][i],d1[j][k]*d1[k+1][i]);
						d1[j][i]=max(d1[j][i],d2[j][k]*d1[k+1][i]);
						d1[j][i]=max(d1[j][i],d1[j][k]*d2[k+1][i]);
						d1[j][i]=max(d1[j][i],d2[j][k]*d2[k+1][i]);
						d2[j][i]=min(d2[j][i],d1[j][k]*d1[k+1][i]);
						d2[j][i]=min(d2[j][i],d2[j][k]*d1[k+1][i]);
						d2[j][i]=min(d2[j][i],d1[j][k]*d2[k+1][i]);
						d2[j][i]=min(d2[j][i],d2[j][k]*d2[k+1][i]);
					
					}	
				}
			}
		}
		int ans = -0x3f3f3f3f;
		for(int i=1;i<=n;++i)
		{
		//	cout<<123<<endl;
		//	cout<<d1[i][i+n-1]<<endl;
			ans = max (ans,d1[i][i+n-1]);
		}
		cout<<ans<<endl;
		int flag = 0;
		for(int i=1;i<=n;++i)
		{
			if(d1[i][i+n-1]==ans)
			{
				if(flag==0)printf("%d",i);
				else {
					printf(" %d",i);
				}
				flag=1;
			}
		}
		cout<<endl;
	}
	return 0;
} 
