#include<bits/stdc++.h>
using namespace std;

int x[1005],y[1005];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)cin>>x[i]>>y[i];
	x[n]=x[0];
	y[n]=y[0];
	int ans=0;
	for(int i=0;i<=n-1;++i)
	{
		int xx=x[i+1]-x[i];
		int yy=y[i+1]-y[i];
		int tx=x[i+2]-x[i+1];
		int ty=y[i+2]-y[i+1];
		if(xx*ty-tx*yy>0)ans++;
	}
	
	cout<<ans<<endl;
}
