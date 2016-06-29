#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<vector>
using namespace std;

int a[10005]; 
int c[2005];
int b[2005];

int main()
{
	int n;
	while(cin>>n)
	{
		memset(b,0,sizeof(b));
		int ans = 0;
		int ma=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
			ma = max(ma,a[i]);
			b[a[i]]++;
			ans = max(ans,b[a[i]]);
		}
		//sort(a,a+n);
		int e=0;
		for(int i=0;i<=2000;++i)
			if(b[i]>0)c[e++]=i;
		//for(int i=0;i<e;++i)cout<<c[i]<<' ';
		//cout<<endl;
		for(int i=1;i<=ma;++i)
		{
			for(int j=0;j<e;++j)
			{
				int num = c[j];
				int k=0;
				while(b[num]>0&&num<=2000)
				{
					k++;
					num+=i;
				}
				//cout<<i<<' '<<k<<endl;
				ans=max(ans,k);
			}
		} 
		
		printf("%d\n",ans);
	}
}
