#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int sum;
	int f=1;
	while(t--)
	{
		int n,x;
		cin>>n;
		int ans=-99999999;
		sum=0;
		int temp=1;
		int begin=0,last=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&x);
			sum+=x;
			if(sum>ans)
			{
				ans=sum;
				last=i;
				begin=temp;
			}
			if(sum<0)
			{
				sum=0;
				temp = i+1;
			}
		}
		cout<<"Case "<<f++<<":"<<endl;
		cout<<ans<<' '<<begin<<' '<<last<<endl;
		if(t>0)cout<<endl;
	}
	
}

