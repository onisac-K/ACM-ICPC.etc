#include<bits/stdc++.h>
using namespace std;
int a[100005];
int dp[100005];
int h[100005];
int ans[100005];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		memset(h,0,sizeof(h));
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		dp[0]=a[0];
		int k=0;
		for(int i=1;i<n;++i)
		{
		
			
			//cout<<a[i]<<' '<<dp[k]<<endl;
			
			if(a[i]>dp[k])
			{
				dp[++k]=a[i];
				h[i]=k;
			}
			else if(a[i]<dp[k])
			{
				
				int l=0,r=k;
				while(l<r-1)
				{
					int mid = (l+r)/2;
					if(dp[mid]>a[i])
					{
						r=mid-1;
					}
					else if(dp[mid]<a[i])l=mid+1;
					else 
					{
						l=mid;
						break;
					}
				}
				if(dp[l]<a[i]&&dp[l+1]>=a[i])
				{
					dp[l+1]=a[i];
					h[i]=l+1;
				}
				else if(dp[l]>=a[i])
				{
					dp[l]=a[i];
					h[i]=l;
				}
				cout<<l<<endl;
			}
			
			else h[i]=k;
		}
		
		/*for(int j=0;j<n;++j)cout<<h[j]<<' ';
		cout<<endl;
		//int ma=0;
		for(int i=n-1;i>=0;--i)
		{
			ma=max(ma,h[i]);
		}*/
		/*cout<<ma<<endl;	
		cout<<k<<endl;*/
		int ma=0;
        for(int i=n-1;i>=0;--i)
        {
            ma=max(ma,h[i]);
        }   
        //cout<<ma<<endl;
        ans[ma+1]=99999999;
        /*for(int i=0;i<n;++i)cout<<h[i]<<' ';
        cout<<endl;*/
        for(int i=n-1;i>=0;--i)
        {
            //cout<<ans[h[i]]<<' '<<ans[h[i]+1]<<endl;
            if(a[i]<ans[h[i]+1])ans[h[i]]=a[i];
        }
        for(int i=0;i<=ma;++i)
        {
            if(i<ma)printf("%d ",ans[i]);
            else printf("%d\n",ans[i]);
        }
        //printf("\n");
	}
	return 0;
}
/*
13
1 7 2 8 3 9 4 10 5 11 6 7 8
*/
