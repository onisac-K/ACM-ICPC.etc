#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*
ֱ��ȡÿ�е���СֵȻ��ȡ��Сֵ�е����ֵ
*/

int G[105][105];

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
				scanf("%d",&G[i][j]);
		}
		int ans=0;
		for(int i=0;i<n;++i)
		{
			int val=1e9+5;
			for(int j=0;j<m;++j)
			{
				val = min(val,G[i][j]);
			}
			ans = max(ans,val);
		}
		cout<<ans<<endl;
	}	
	return 0;
}
