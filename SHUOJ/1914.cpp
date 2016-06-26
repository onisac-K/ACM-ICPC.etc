#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		char q[10];
		int a=1500,b=1500;
		for(int i=0;i<n;++i)
		{
			scanf("%s",q);
			if(q[0]=='g')
			{
				if(a>=b)
				{
					if(b<1700)b+=233;
					else b+=123;
				}
				else
				{
					if(a<1700)a+=233;
					else a+=123;
				}
			}
			else 
			{
				if(a>=b)
				{
					if(b<1700)b-=123;
					else b-=233;
				}
				else
				{
					if(a<1700)a-=123;
					else a-=233;
				}
			}
			cout<<a<<' '<<b<<endl;
		}
		int ans = (a>b)? a:b;
		cout<<ans<<endl;
	}
	return 0;
} 
