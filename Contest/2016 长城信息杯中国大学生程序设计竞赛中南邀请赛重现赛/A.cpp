#include<bits/stdc++.h> 
using namespace std;
char m[100005];
int main()
{
	while(cin>>m)
	{
		int n=0;
		int L = strlen(m);
		for(int i=0;i<L;++i)
		{
			n=n*10+(int)(m[i]-'0');
			n%=2016;
		}
		//cout<<n<<endl;
		
		int a[2][2];
		int ans[2][2];
		for(int i=0;i<2;++i)
		{
			for(int j=0;j<2;++j)
			{
				cin>>a[i][j];
				ans[i][j]=a[i][j];
			}
		}
		if(n==0)
		{
			cout<<1<<' '<<0<<endl<<0<<' '<<1<<endl;
			continue;
		}
		int f[2][2]; 		
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<2;++j)
			{
				for(int k=0;k<2;++k)f[j][k]=ans[j][k];
			}
			ans[0][0]=f[0][0]*a[0][0]+f[0][1]*a[1][0];
			ans[0][1]=f[0][0]*a[0][1]+f[0][1]*a[1][1];
			ans[1][0]=f[1][0]*a[0][0]+f[1][1]*a[1][0];
			ans[1][1]=f[1][0]*a[0][1]+f[1][1]*a[1][1];
			for(int j=0;j<2;++j)
			{
				for(int k=0;k<2;++k)ans[j][k]%=7;
			}
		}
		for(int i=0;i<2;++i)
		{
			cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
		}
	}
	return 0;
}
