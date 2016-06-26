#include<bits/stdc++.h>
using namespace std;

int cnt[30];
int str[26*55];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=26;++i)scanf("%d",&cnt[i]);
		sort(cnt+1,cnt+1+26);
		int n=0;
		for(int i=1;i<=26;++i)
		{
			if(cnt[i]==0)continue;
			if(i==26)
			{
				for(int j=1;j<=cnt[i]-1;++j)n+=j;
			}
			else 
			{
				n=cnt[i]-1;
			}
			break;
		}
		cout<<n<<endl;
	}
	return 0;
} 

/*
1
4 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
