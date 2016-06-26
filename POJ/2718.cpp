#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
using namespace std;

set<int> n1;
set<int> n2;
int num1[6],num2[6];
int k1,k2;
char a[100];
int num[15];
int sel[15];
int vis[50];
int mi=999999;

void dfs1(int i,int k)
{
	//cout<<k<<' '<<k1<<endl;
	if(i==0&&k==0)return ;
	if(k==k1-1)
	{
	//	cout<<i<<endl;
		if(!n1.count(i))n1.insert(i);
		return ;
	}
	//cout<<i<<endl;
	for(int j=0;j<k1;++j)
	{
		if(vis[j]==0)
		{
			vis[j]=1;
			dfs1(i*10+num1[j],k+1);
			vis[j]=0;
		}
	}
}

void dfs2(int i,int k)
{
	//cout<<k<<' '<<k1<<endl;
	if(i==0&&k==0)return ;
	if(k==k2-1)
	{
	//	cout<<i<<endl;
		if(!n2.count(i))n2.insert(i);
		return ;
	}
	//cout<<i<<endl;
	for(int j=0;j<k2;++j)
	{
		if(vis[j]==0)
		{
			vis[j]=1;
			dfs2(i*10+num2[j],k+1);
			vis[j]=0;
		}
	}
}
	
int main()
{
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		gets(a);
		int l=strlen(a);
		int k=0;
		int flag=0;
		for(int i=0;i<l;++i)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				num[k++]=(int)(a[i]-'0');
			}
		}
		//for(int i=0;i<k;++i)cout<<num[i]<<' ';
		//cout<<endl;
		int left=k/2;
		int right=k-left;
		int n=1;
		for(int i=0;i<k;++i)n*=2;
		//cout<<n<<endl;
		
		for(int i=0;i<=n;++i)
		{
			int s=i;
			int j=0;
			int q=0;
			memset(sel,0,sizeof(sel));
			while(s>0)
			{
				if(s%2==1)q++;
				sel[j++]=s%2;
				if(q==left||q==right)break;
				s/=2;
			}
			if(q!=left || q!=right)continue;
			k1=0,k2=0;
			for(int o=0;o<k;++o)
			{
				if(sel[o]==1)num1[k1++]=num[o];
				else num2[k2++]=num[o];
			}
			/*for(int ii=0;ii<k1;++ii)cout<<num1[ii]<<endl;
			cout<<endl;
			for(int ii=0;ii<k2;++ii)cout<<num2[ii]<<endl;
			cout<<"end"<<endl;*/
			n1.clear();
			n2.clear();
			for(int o=0;o<k1;++o)
			{
				memset(vis,0,sizeof(vis));
				vis[o]=1;
				dfs1(num1[o],0);
			}
			for(int o=0;o<k2;++o)
			{
				memset(vis,0,sizeof(vis));
				vis[o]=1;
				dfs2(num2[o],0);
			}
			//cout<<123<<endl;
			set<int>::iterator it;
			set<int>::iterator it1;
			set<int>::iterator it2;
		/*	for(it=n1.begin();it!=n1.end();it++)cout<<*it<<endl;
			cout<<endl;
			for(it=n2.begin();it!=n2.end();it++)cout<<*it<<endl;
			cout<<"end"<<endl;*/
			for(it1=n1.begin();it1!=n1.end();it1++)
			{
				for(it2=n2.begin();it2!=n2.end();it2++)
				{
					int ans=*(it1)-*(it2);
					if(ans<0)ans*=-1;
					mi=min(ans,mi);
				}
			}
		}
		printf("%d\n",mi);	
	}
	return 0;
} 
