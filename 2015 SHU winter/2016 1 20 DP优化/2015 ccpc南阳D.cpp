#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp1[4005][3],dp2[4005][3];

int main()
{
	int t;
	cin>>t;
	int f=1;
	while(t--)
	{
		int n,L;
		memset(dp1,-1,sizeof(dp1));
		memset(dp2,-1,sizeof(dp2));
		scanf("%d%d",&n,&L);
		dp1[0][0]=0;
		dp2[0][0]=0;
		L*=2;
		ll a,v;
		ll ans=-1;
		for(int i=0;i<n;++i)
		{
			scanf("%lld%lld",&a,&v);
			a*=2;
			for(int j=0;j<=L;++j)
			for(int k=0;k<3;++k)dp2[j][k]=dp1[j][k];
			for(int j=0;j<=L;++j)
			{
				if(j+a<=L)
				{
					if(dp2[j][0]!=-1)dp1[j+a][0]=max(dp2[j][0]+v,dp1[j+a][0]);
					if(dp2[j][1]!=-1)dp1[j+a][1]=max(dp2[j][1]+v,dp1[j+a][1]);
					if(dp2[j][2]!=-1)dp1[j+a][2]=max(dp2[j][2]+v,dp1[j+a][2]);
				}
				if(j+a/2<=L)
				{
					if(dp2[j][0]!=-1)dp1[j+a/2][1]=max(dp2[j][0]+v,dp1[j+a/2][1]);
					if(dp2[j][1]!=-1)dp1[j+a/2][2]=max(dp2[j][1]+v,dp1[j+a/2][2]);
				}
				if(a>=L) 
				{
					dp1[L][2]=max(dp1[L][2],dp2[0][0]+v);
				}
				for(int k=0;k<3;++k)ans=max(ans,dp1[j][k]);
			}	
		}
		printf("Case #%d: ",f++);
		printf("%lld\n",ans);
		
	}
	return 0;
} 
