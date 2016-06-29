#include<bits/stdc++.h>
using namespace std;

struct node{
	int len;
	string s;
	/*friend bool operator < (node a, node b)
	{
		if(a.len != b.len)return a.len < b.len;
		else return a.s > b.s;
	}*/
	bool operator <(const node &x) const
    {
        if( len == x.len ) return s > x.s;
        else return len < x.len;
    }
}dp[1005][1005];

char a[1005];
char b[1005];

void init(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        dp[0][i].len = 0;
        dp[0][i].s.clear();
        dp[i][0].len = 0;
        dp[i][0].s.clear();
    }
}

int main()
{
	while(scanf("%s", a+1)!=EOF)
	{
		int L = strlen(a+1);
		/*for(int i=0;i<=L;++i)
		{
			for(int j=0;j<=L;++j)
			{
				dp[i][j].len=0;
				dp[i][j].s.clear();
				
			}
		}*/
		init(L);
		for(int i=1;i<=L;++i){
			b[i]=a[L+1-i];
		}
		//cout<<a+1<<endl<<b+1<<endl;
		node ans;
		ans.len=0;
		ans.s.clear();
		for(int i=1;i<=L;++i)
		{
			for(int j=1;j<=L;++j)
			{
				if(a[i]==b[j])
				{
					dp[i][j].len=dp[i-1][j-1].len+1;
					dp[i][j].s=dp[i-1][j-1].s+a[i];
				}
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				//ans=max(ans,dp[i][j]);
			}
		}
		for(int i=1;i<L;++i)
		{
			ans=max(ans,dp[i][L-i]);
		}
		//cout<<ans.s<<endl;
		ans.len*=2;
		node ans2;
		ans2.len=0;
		ans2.s.clear();
		for(int i=0;i<L;++i)
		{
			ans2=dp[i][L-1-i];
			ans2.len=ans2.len*2+1;
			ans2.s+=a[i+1];
			ans=max(ans,ans2);
		}
		strcpy(a+1,ans.s.c_str());
		//cout<<(ans.len)<<endl;
		for(int i=1;i<=ans.len/2;++i)printf("%c",a[i]);
		if(ans.len&1)for(int i=ans.len/2+1;i>=1;--i)printf("%c",a[i]);
		else for(int i=ans.len/2;i>=1;--i)printf("%c",a[i]);
		cout<<endl;
		//if(ans.len%2==0)
	}
	return 0;
} 
/*
aabbaabb
computer
abzla
samhita
*/
