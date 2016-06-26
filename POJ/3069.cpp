#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int x[1005];

int main()
{
	int r,n;
	while(cin>>r>>n)
	{
		memset(x,0,sizeof(x));
		if(r==-1&&n==-1)break;
		for(int i=0;i<n;++i)scanf("%d",&x[i]);
		sort(x,x+n);
		n=unique(x,x+n)-x;
		//cout<<n<<endl;
		int c=0;
		int y=0;
		while(y<n)
		{
			int k=x[y]+r;
			int i;
			for(i=y;i<n;++i)
			{
				if(x[i+1]>k)break;
			}
			if(i==y)
			{
				c++;y++;continue;
			}
			if(i<n)
			{
				//cout<<x[i]<<' ';
				k=x[i]+r;
				int j;
				for(j=i;j<n;++j)
				{
					if(x[j+1]>k)break;
				}
				//cout<<x[j]<<endl;
				y=j+1;
				c++;
			}
			else 
			{
				c++;
				break;
			}
		}
		cout<<c<<endl;
	}
}
