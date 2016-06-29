#include<bits/stdc++.h>
using namespace std;

int a[1005][2];
int c[1005][2];
int b[2005];
int n,k;

int  main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int l = 0;
		for(int i=0;i<k;++i)
		{
			scanf("%d%d",&a[i][0],&a[i][1]);
			b[l++]=a[i][0];
			b[l++]=a[i][1];
		}
		sort(b,b+l);
		int L = unique(b,b+l)-b;
		map<int,int>ma;
		for(int i=0;i<L;++i)
			ma[b[i]]=i+1;
		for(int i=0;i<k;++i)
		{
			c[i][0]=ma[a[i][0]];
			c[i][1]=ma[a[i][1]];	
		}
		map<int,int> q;
		//cout<<"L"<<' '<<L<<endl;
		for(int i=0;i<k;++i)
		{
			q[c[i][0]]=c[i][1];	
		}
		for(int i=1;i<=L;++i)
		{
			if(q[i]==0)q[i]=i+1;
		}
		/*
		for(int i=0;i<k;++i)
			cout<<c[i][0]<<' '<<c[i][1]<<endl;
		*/
		int x=1;
		int step=0;
		while(x!=L+1 && step<=L+1)
		{
			if(x==L+1)break;
			//cout<<x<<' '<<q[x]<<endl;
			x=q[x];
			step++;
		}
		if(x==L+1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
