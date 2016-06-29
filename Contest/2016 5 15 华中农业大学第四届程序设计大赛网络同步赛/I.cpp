#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	
	while(cin>>n>>m)
	{
		double t=0;
		double tx=0;
		double x,v,vc;
		int flag=0;
		for(int i=0;i<n;++i)
		{
			
			//cout<<t<<' '<<tx<<endl;
			cin>>x>>v;
			if(flag==1)continue;
			x=x+v*t;
			//cout<<x<<endl;
			if(x==tx)continue;
			if(x>tx)
			{
				if(v<0)
				{	
					//m=fabs(m);
					double t1=(x-tx)*1.0/(-1*v+m);
					t+=t1;
					tx=x+v*t1;
				}
				else 
				{
					//m=fabs(m);
					if(v>=m)
					{
						flag=1;
						//break;
					}	
					double t1=(x-tx)*1.0/(m-v);
					t+=t1;
					tx=x+v*t1;
				}
			}
			else //x<tx
			{
				if(v>0)
				{
					//m=fabs(m);
					double t1=(tx-x)*1.0/(v+m);
					t+=t1;
					tx=x+v*t1;
				}
				else 
				{
					//m=fabs(m);
					if((-1*v)>=m)
					{
						flag=1;
						//break;
					}	
					double t1=(tx-x)*1.0/(m+v);
					t+=t1;
					tx=x+v*t1;
				}
			}
			
		}
		if(flag==1)cout<<"Bad Dog"<<endl;
		else printf("%.2f\n",t);
	}
} 
