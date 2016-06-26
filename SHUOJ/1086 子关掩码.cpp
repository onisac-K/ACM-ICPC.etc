#include<bits/stdc++.h>
using namespace std;

int main()
{
	int b[4];
	int bb[4][10];
	int kk[4][10];
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<8;++j)
		{
			bb[i][j]=0;
			kk[i][j]=0;
		}
	}
	scanf("%d.%d.%d.%d",&b[0],&b[1],&b[2],&b[3]);
	//for(int i=0;i<4;++i)cout<<b[i]<<endl;
	for(int i=0;i<4;++i)
	{
		int s=b[i];
		int j=0;
		while(s>0)
		{
			//cout<<s<<endl;
			bb[i][j++]=s%2;
			s/=2;
			if(j>8)break;
		}
	}
	/*for(int i=0;i<4;++i)
	{
		for(int j=0;j<8;++j)cout<<bb[i][j];
		cout<<endl;
	}*/
	int k[4];
	scanf("%d.%d.%d.%d",&k[0],&k[1],&k[2],&k[3]); 
	for(int i=0;i<4;++i)
	{
		int s=k[i];
		int j=0;
		while(s>0)
		{
			//cout<<s<<endl;
			kk[i][j++]=s%2;
			s/=2;
			if(j>8)break;
		}
	}
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<8;++j)
		{
			bb[i][j]=bb[i][j]&kk[i][j];
		}
	}
	/*for(int i=0;i<4;++i)
	{
		for(int j=0;j<8;++j)cout<<bb[i][j];
		cout<<endl;
	}*/

	int n;
	cin>>n;
	for(int ij=0;ij<n;++ij)
	{
		int p[4];
		int pp[4][10];
		for(int i=0;i<4;++i)
			for(int j=0;j<8;++j)pp[i][j]=0;
		scanf("%d.%d.%d.%d",&p[0],&p[1],&p[2],&p[3]);
		for(int i=0;i<4;++i)
		{
			int s=p[i];
			int j=0;
			while(s>0)
			{
				//cout<<s<<endl;
				pp[i][j++]=s%2;
				s/=2;
				if(j>8)break;
			}
		} 
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<8;++j)
			{
				pp[i][j]=pp[i][j]&kk[i][j];
			}
		}
		int flag=1;
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<8;++j)
			{
				if(bb[i][j]!=pp[i][j])
				{
					flag=0;
					break;
				}
			}
			if(!flag)break;
		}
		if(flag)cout<<"INNER"<<endl;
		else cout<<"OUTER"<<endl;
	}
	return 0;
}
