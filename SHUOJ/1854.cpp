#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int ans[1000005];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int k;
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		scanf("%d",&k);
		for(int i=0;i<n;++i)ans[i]=a[i];
		/*scanf("%d",&k);
		vector<int> v[10];
		for(int i=0;i<n;++i)
		{
			v[a[i]%10].push_back(a[i]);	
		}
		//cout<<123<<endl;
		int jj=0;
		for(int i=0;i<10;++i)
		{				
			int x=v[i].size();
			for(int k=0;k<x;++k)a[jj++]=v[i][k];
			v[i].clear();
		}
		//for(int i=0;i<n;++i)cout<<a[i]<<endl;	
		for(int i=0;i<n;++i)
		{
			v[(a[i]/10)%10].push_back(a[i]);
		}
		jj=0;
		for(int i=0;i<10;++i)
		{				
			int x=v[i].size();
			for(int k=0;k<x;++k)a[jj++]=v[i][k];
			v[i].clear();
		}
		
		for(int i=0;i<n;++i)
		{
			v[(a[i]/100)%10].push_back(a[i]);
		}
		jj=0;
		for(int i=0;i<10;++i)
		{				
			int x=v[i].size();
			for(int k=0;k<x;++k)a[jj++]=v[i][k];
			v[i].clear();
		}*/
	//	for(int i=0;i<n;++i)cout<<a[i]<<endl;
		int mid1=n/2-1;
        int mid2=n/2;
        nth_element(a,a+mid1,a+n); mid1=a[mid1];
        nth_element(a,a+mid2,a+n); mid2=a[mid2];
        if(n&1)mid1=mid2;
		if(n==1)
		{
			cout<<"YES"<<endl<<1<<endl;
		}
		int num=0;
		int f=0;
		for(int i=0;i<n;++i)
		{
			if(fabs(a[i]-mid1)<=2*k||fabs(a[i]-mid2)<=2*k)
			{
				num++;
				f=a[i];
			}
		}
		if(num==1)
		{
			printf("YES\n");
			int q=0;
			for(int i=0;i<n;++i)if(ans[i]==f)q=i+1;
			printf("%d\n",q);	
		}
		else 
		{
			printf("NO\n");
			printf("%d\n",num);
		}
	}

	
	return 0;
}
