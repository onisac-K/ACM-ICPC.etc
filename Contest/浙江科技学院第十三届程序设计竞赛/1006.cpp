#include<bits/stdc++.h>
using namespace std;

int a[1005],b[1005];
int vb[1005],va[1005];

int main()
{
	int n;
	while(cin>>n)
	{
		memset(vb,0,sizeof(vb));
		memset(va,0,sizeof(va));
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		for(int i=0;i<n;++i)scanf("%d",&b[i]);
		sort(a,a+n);sort(b,b+n);
		//for(int i=0;i<n;++i)b[n+i]=b[i];
		int ma=0;
		int ti=0,tj=n-1;
		int ki=0,kj=n-1;
		int num=0;
		while(ti<=tj)
		{
			if(a[tj]>b[kj])
			{
				num++;
				tj--;
				kj--;
			}
			else if(a[ti]>b[ki])
			{
				num++;
				ti++;
				ki++;
			}
			else 
			{
				if(a[ti]<b[kj])num--;
				ti++;
				kj--;
			}
		}
		ma=num*100;
		cout<<ma<<endl;
	}
	return 0;
}
