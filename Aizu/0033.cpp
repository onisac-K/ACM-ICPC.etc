#include<bits/stdc++.h>
using namespace std;
int a[10];

bool solve()
{
	int l[15],r[15];
	for(int i=0;i<=1024;++i)
	{
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		int j=i;
		int L=0,R=0;
		for(int k=0;k<10;++k,j>>=1)
		{
			if(j&1)l[L++]=a[k];
			else r[R++]=a[k];
		}
		int flag=1;
		for(int k=1;k<L;++k)
		{
			if(l[k]<l[k-1])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			for(int k=1;k<R;++k)
			{
				if(r[k]<r[k-1])
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)return 1;
	}
	return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<10;++i)cin>>a[i];
		cout<<((solve())? "YES":"NO")<<endl;
	}
	return 0;
}
