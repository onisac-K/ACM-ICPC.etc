#include<bits/stdc++.h>
using namespace std;

#define INF 0x3ffffff

int n,k;
struct point{
	int x;
	int y;
}p[1000];

int dp[55][55][5];

bool cmp(point a,point b)
{
	if(a.y==b.y)return a.x<b.x;
	else return a.y<b.y;
}

int main()
{
	while(cin>>n>>k)
	{
		for(int i=0;i<55;++i)
		{
			for(int j=0;j<55;++j)
			{
				for(int p=0;p<5;++p)dp[i][j][p]=INF;
			}
		}
		for(int i=0;i<n;++i)scanf("%d%d",&p[i].x,&p[i].y);
		sort(p,p+n,cmp);
		//for(int i=0;i<n;++i)cout<<p[i].x<<' '<<p[i].y<<endl;
		
		for(int i=0;i<n;i++)
    	{
      	 	int l=p[i].x,r=p[i].x;
      	 	for(int j=i;j<n;j++)
        	{
         		l=min(l,p[j].x);r=max(r,p[j].x);
 	     		dp[i][j][1]=(p[j].y-p[i].y)*(r-l);
        	}
		}
		/*for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)cout<<dp[i][j][1]<<endl;
	 	 } */
		for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        for(int q=i;q<j;q++)
    	{
            dp[i][j][2]=min(dp[i][q][1]+dp[q+1][j][1],dp[i][j][2]);
   		}
    	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        for(int q=i;q<j;q++)
        {
            dp[i][j][3]=min(dp[i][q][1]+dp[q+1][j][2],dp[i][j][3]);
            dp[i][j][3]=min(dp[i][q][2]+dp[q+1][j][1],dp[i][j][3]);
        }
		cout<<dp[0][n-1][k]<<endl;
	}
	
}
