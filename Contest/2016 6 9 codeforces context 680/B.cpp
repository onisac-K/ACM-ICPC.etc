#include<bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
	int n,aa;
	cin>>n>>aa;
	int ans = 0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	if(a[aa]==1)ans++;
	for(int i=1;i<=n;++i)
	{
		if(aa+i<=n&&aa-i>=1)
		{
			if(a[aa+i]==1&&a[aa-i]==1)ans+=2;
		}
		else if(aa+i<=n&&a[aa+i]==1) ans+=1;
		else if(aa-i>=1&&a[aa-i]==1) ans+=1;
		else if(aa+i>n&&aa-i<1)break;
	}
	cout<<ans<<endl;
	
	return 0;
 } 
