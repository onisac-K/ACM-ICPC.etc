#include<bits/stdc++.h>
using namespace std;
char a[100];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",a);
		int l=strlen(a);
		int  op=0;
		for(int i=0;i<l;++i)
		{
			op=op*10+(a[i]-'0');
		}
		int num=0;
		for(int i=0;i<l;++i)
		{
			if(a[i]=='8')num++;
		}
		if(num==3)
		{
			puts(a);
		}
		else if(l<=3)cout<<888<<endl;
		else if(num>3)
		{
			int k=0;
			for(int i=0;i<l;++i)
			{
				if(a[i]=='8')k++;
				if(k==3)
				{	
					for(int j=i+1;j<l;++j)
					{
						if(a[j]=='8')
						{
							a[j]='9';
							for(int p=j+1;p<l;++p)a[p]='0';
							break;
						}
					}
					break;
				}
			}
			puts(a);
		}
		else if(num<3)
		{
			int s=0;
			int k=3-num;
			for(int i=l-1;i>=0&&k>0;--i)
			{
				if(a[i]=='8')continue;
				else  
				{
					a[i]='8';
					k--;
				}
			}
			
			for(int i=0;i<l;++i)s=s*10+(a[i]-'0');
			if(s<op)
			{
				for(int i=l-1;i>=0;--i)
				{
					if(a[i]=='8')continue;
					else if(a[i]=='7'){
						a[i]==9;
						break;
					}
					else if(a[i]=='9')
					{
						int qqq=0;
						cout<<123<<endl;
						for(int j=i-1;j>=0;--j)
						{
							if(a[j]<'8')
							{
								if(a[j]<'7')a[j]=a[j]+1;
								else a[j]='9';
								for(int k=i;k>j;--k)a[k]='0';
								qqq=1;
								break;
							}
							if(qqq==1)break;
						}
						break;
					}
					else if(a[i]<'7'){
						a[i]=a[i]+1;
						break;
					}
				}
			}
			puts(a);
		}
	}
	return 0;
 } 
