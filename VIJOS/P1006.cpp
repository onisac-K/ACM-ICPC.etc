#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int a[1005][1005];
int n;

void debug()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)cout<<dp[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
}

int main()
{

	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	// n 
	dp[n][1]=a[n][1];
	for(int i=2;i<=n;++i)
	{
		int k1=0,k2=a[n][1];
		for(int j=1;j<=i;++j)k1+=a[n][j];
		for(int j=i;j<=n;++j)k2+=a[n][j];
		dp[n][i]=min(k1,k2);
	}
	
	for(int i=n-1;i>=1;--i)
	{

		for(int j=1;j<=i;++j)
		{
			
			if(j==1)
			{
				//cout<<dp[i][1]<<endl;				
				dp[i][1]=min(a[i][1]+dp[i+1][2],min(a[i][1]+dp[i+1][i+1],a[i][1]+dp[i+1][1]));
				//cout<<dp[i][1]<<endl;
				//cout<<dp[i+1][2]<<' '<<dp[i+1][i+1]<<' '<<dp[i+1][1]<<endl;
				
			}
			else if(j==i)
				dp[i][i]=min(a[i][i]+dp[i+1][i],min(a[i][j]+dp[i+1][1],a[i][j]+dp[i+1][i+1]));
			else dp[i][j]=min(a[i][j]+dp[i+1][j],a[i][j]+dp[i+1][j+1]);
		}
		/*int j;
		int mins=9999999;
		for(int jj=1;jj<=i;++jj)
		{
			if(dp[i][jj]<mins)
			{
				mins=dp[i][jj];
				j=jj;
			}
		}
		for(int k=j-1;k>=1;--k)
			{
				int f=dp[i][k];
				dp[i][k]=min(dp[i][k],dp[i][k+1]+a[i][k]);
				//cout<<f<<' '<<dp[i][k]<<endl;
				if(dp[i][k]==f&&k!=1)break;
				if(k==1)
				{
					dp[i][1]=min(dp[i][1],dp[i][2]+a[i][1]);
					dp[i][1]=min(dp[i][1],dp[i][i]+a[i][1]);
					dp[i][i]=min(dp[i][i],dp[i][1]+a[i][i]);
				}
			}
			for(int k=j+1;k<=i;++k)
			{
				int f=dp[i][k];
				dp[i][k]=min(dp[i][k],dp[i][k-1]+a[i][k]);
				if(f==dp[i][k]&&k!=i)break;
				if(k==i)
				{
					dp[i][i]=min(dp[i][i],dp[i][i-1]+a[i][i]);
					dp[i][i]=min(dp[i][i],dp[i][1]+a[i][i]);
					dp[i][1]=min(dp[i][1],dp[i][i]+a[i][1]);
				}
			}*/
	//	debug();
		for(int j=1;j<=i;++j)
		{
			for(int k=j-1;k>=1;--k)
			{
				int f=dp[i][k];
				dp[i][k]=min(dp[i][k],dp[i][k+1]+a[i][k]);
				//cout<<f<<' '<<dp[i][k]<<endl;
				if(dp[i][k]==f&&k!=1)break;
				if(k==1)
				{
					dp[i][1]=min(dp[i][1],dp[i][2]+a[i][1]);
					dp[i][1]=min(dp[i][1],dp[i][i]+a[i][1]);
					dp[i][i]=min(dp[i][i],dp[i][1]+a[i][i]);
				}
			}
			for(int k=j+1;k<=i;++k)
			{
				int f=dp[i][k];
				dp[i][k]=min(dp[i][k],dp[i][k-1]+a[i][k]);
				if(f==dp[i][k]&&k!=i)break;
				if(k==i)
				{
					dp[i][i]=min(dp[i][i],dp[i][i-1]+a[i][i]);
					dp[i][i]=min(dp[i][i],dp[i][1]+a[i][i]);
					dp[i][1]=min(dp[i][1],dp[i][i]+a[i][1]);
				}
			}
		}
		for(int j=1;j<=i;++j)
		{
			for(int k=j-1;k>=1;--k)
			{
				int f=dp[i][k];
				dp[i][k]=min(dp[i][k],dp[i][k+1]+a[i][k]);
				//cout<<f<<' '<<dp[i][k]<<endl;
				if(dp[i][k]==f&&k!=1)break;
				if(k==1)
				{
					dp[i][1]=min(dp[i][1],dp[i][2]+a[i][1]);
					dp[i][1]=min(dp[i][1],dp[i][i]+a[i][1]);
					dp[i][i]=min(dp[i][i],dp[i][1]+a[i][i]);
				}
			}
			for(int k=j+1;k<=i;++k)
			{
				int f=dp[i][k];
				dp[i][k]=min(dp[i][k],dp[i][k-1]+a[i][k]);
				if(f==dp[i][k]&&k!=i)break;
				if(k==i)
				{
					dp[i][i]=min(dp[i][i],dp[i][i-1]+a[i][i]);
					dp[i][i]=min(dp[i][i],dp[i][1]+a[i][i]);
					dp[i][1]=min(dp[i][1],dp[i][i]+a[i][1]);
				}
			}
		}
		//debug();
	}
	//debug();
	cout<<dp[1][1]<<endl;
	return 0;
} 
 
 /*
 5
 1
 2 3
 5 5 0
 1 1 1 0
 1 1 1 1 0
 */
