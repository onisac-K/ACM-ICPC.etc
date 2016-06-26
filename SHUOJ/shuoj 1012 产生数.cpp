#include<bits/stdc++.h>
using namespace std;

int a[10][10]={0};
char num[1000];
int sum[10]={0};
int ans[1000]={0};

int main()
{
	scanf("%s",num);
	int k;
	scanf("%d",&k);
	int x,y;
	for(int i=0;i<k;++i)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=1;
	}
	for(int i=0;i<=9;++i)a[i][i]=1;
	for(int k=0;k<=9;++k)
	{
		for(int i=0;i<=9;++i)
		{
			for(int j=0;j<=9;++j)
			{
				if(a[i][k]&&a[k][j])a[i][j]=1;
			}
		}
	}
	for(int i=0;i<=9;++i)
	{	
		for(int j=0;j<9;++j)
		{
			sum[i]+=a[i][j];
		}			
	}
	//for(int i=0;i<9;++i)cout<<sum[i]<<endl;
	ans[0]=1;
	int maxn=0;
	int n=strlen(num);
	for(int i=0;i<n;++i)
	{
		int nu=num[i]-'0';
		nu=sum[nu];
		int jin=0,cnt=0;
		for(;cnt<=maxn||jin;++cnt)
		{
			ans[cnt]=nu*ans[cnt]+jin;
			jin=ans[cnt]/10;
			ans[cnt]%=10;
		}
		if(cnt>maxn+1)maxn=cnt-1;
	}
	for(int i=maxn;i>=0;--i)printf("%d",ans[i]);
}
