#include<bits/stdc++.h>
using namespace std;


int ans[100000][6];
char f[6];
int vis[1000000];

int main()
{
	int m=0;
	for(int i=0;i<=9;++i)
	{
		for(int j=0;j<=9;++j)
		{
			for(int k=0;k<=9;++k)
			{
				for(int q=0;q<=9;++q)
				{
					for(int p=0;p<=9;++p)
					{
						ans[m][0]=i;
						ans[m][1]=j;
						ans[m][2]=k;
						ans[m][3]=q;
						ans[m][4]=p;
						m++;
					}
				}
			}
		}
	}
	//cout<<m<<endl;
	int t;
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		int n;
		cin>>n;
		int x;
		int a,b;
		for(int i=0;i<n;++i)
		{
			scanf("%s",f);
			scanf("%d%d",&a,&b);
			for(int j=0;j<m;++j)
			{
				int c=0;
				for(int k=0;k<5;++k)
				{
					if(f[k]-'0'==ans[j][k])c++;
				}
				int bb[10];
				memset(bb,0,sizeof(bb));
				for(int k=0;k<5;++k)
				{
					for(int q=0;q<5;++q)
					{
						if(bb[q]==0&&(f[k]-'0')==ans[j][q])
						{
							bb[q]=1;
							break;
						}
					}
				}
				int l=0;
				for(int k=0;k<5;++k)if(bb[k]==1)l++;
				if(c!=a||l!=b)vis[j]=1;
			}
		}
		int op=0;
		for(int i=0;i<m;++i)if(vis[i]==0)op++;
		printf("%d\n",op);
	}
	return 0;
}
