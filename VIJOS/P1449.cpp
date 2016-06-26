#include<bits/stdc++.h>
using namespace std;
char a[3][10005];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<3;++i)scanf("%s",a[i]);
	//cout<<a[1]<<endl<<a[2]<<endl<<a[0]<<endl;
	int vis[3]={0};
	for(int i=0;i<n;++i)
	{
		//cout<<('z'+'b'-2*'a')<<endl;
		if((a[0][i]+a[1][i]-a[2][n-1-i]*2)%26==0)vis[2]++;
		if((a[0][i]+a[2][i]-a[1][n-1-i]*2)%26==0)vis[1]++;
		if((a[1][i]+a[2][i]-a[0][n-1-i]*2)%26==0)vis[0]++;
	}
	if(vis[2]>=vis[1]&&vis[2]>=vis[0])	
		for(int i=n-1;i>=0;--i)printf("%c",a[2][i]);
	
	else if(vis[1]>=vis[2]&&vis[1]>=vis[0])
		for(int i=n-1;i>=0;--i)printf("%c",a[1][i]);
	else for(int i=n-1;i>=0;--i)printf("%c",a[0][i]); 
}
