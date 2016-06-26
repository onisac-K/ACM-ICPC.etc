#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
int L[20005];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)scanf("%d",&L[i]);
	ll ans=0;
	while(n>1)
	{
		int m1=0,m2=1;
		if(L[m1]>L[m2])swap(m1,m2);
		for(int i=2;i<n;++i)
		{
			if(L[i]<L[m1])
			{
				m2=m1;
				m1=i;
			}
			else if(L[i]<L[m2])
			{
				m2=i;
			}
		}
		int t=L[m1]+L[m2];
		ans+=t;
		if(m1==n-1)swap(m1,m2);
		L[m1]=t;
		L[m2]=L[n-1];
		n--;
	}
	cout<<ans<<endl;
	return 0;
}
