#include<bits/stdc++.h>
using namespace std;

char a[56];
int num[56];
int vis[56];
int loop[56];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",a);
		for(int i=0;i<26;++i)num[i]=(a[i]-'A');
		memset(vis,0,sizeof(vis));
		memset(loop,0,sizeof(loop));
		for(int i=0;i<26;++i)
		{
			int c=0;
			int j=i;
			while(!vis[j])
			{
				vis[j]=1;
				j=num[j];
				c++;
				
			}
			loop[c]++;
		}
		
		int flag=0;
		for(int i=0;i<26;i+=2)
		{
		//	cout<<loop[i]<<' ';
			if(loop[i]!=0)
			{
				if(loop[i]&1)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
