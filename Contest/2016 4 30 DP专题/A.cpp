#include<bits/stdc++.h>
using namespace std;

int dp[255*255];
int q[255*255],p[255*255];
int f[255*255];

int main()
{
	int t;
	cin>>t;
	int fff=1;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		int n,qq,pp;
		cin>>n>>pp>>qq;
		for(int i=1;i<=pp+1;++i)scanf("%d",&p[i]);
		int a;
		for(int j=1;j<=qq+1;++j)
		{
			scanf("%d",&a);
			q[a]=j; 
		}
		for(int i=1;i<=pp+1;++i)
		{
			p[i]=q[p[i]];
		}
		int len=0;
		for(int i=1;i<=pp+1;i++){
			int l=1,r=len;
			while(l<=r){
				int mid=(l+r)>>1;
				if(f[mid]<p[i])
				 l=mid+1;
				else
				r=mid-1;
			}
		    f[l]=p[i];
		    len=max(len,l);
		    dp[i]=l;
		}
		/*for(int i=1;i<=pp+1;++i)cout<<p[i]<<' ';
		cout<<endl;
		for(int i=1;i<=pp+1;++i)cout<<dp[i]<<' ';
		cout<<endl;*/
		printf("Case %d: %d\n",fff++,len);
	}
	return 0;
}


/*
3 6 7

1 7 5 4 8 3 9

1 4 3 5 6 2 8 9 

*/ 
