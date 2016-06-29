#include<bits/stdc++.h>
using namespace std;

int s[10005];
int num[10000];
int main()
{
	char c;
	int a;
	int n=0;
	int f=1;
	while(scanf("%d%c",&a,&c)!=EOF)
	{
		if(c==' '){
			s[n++]=a;
		}
		if(c=='\n')
		{
			memset(num,0,sizeof(num));
			s[n++]=a;
			int k=0;
			for(int i=0;i<n;++i)
			{
				if(s[i]!=-123991234)num[k++]=s[i];
				for(int j=i+1;j<n;++j)
				{
					if(s[i]==s[j])s[j]=-123991234;
				}
			}
		
			printf("Case %d: ",f++);
			for(int i=0;i<k;++i)
			{
				
				if(i<k-1)printf("%d ",num[i]);
				else cout<<num[i]<<endl;
			}
			n=0; 
		}
	}
	return 0;
}
