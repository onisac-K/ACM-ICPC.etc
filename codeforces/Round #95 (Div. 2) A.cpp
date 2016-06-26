#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[105];
	scanf("%s",a);
	int flag=0;
	int len=strlen(a);
	for(int i=1;i<len;++i)
	{
		if(a[i]>='a'&&a[i]<='z')
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		cout<<a<<endl;
	}
	else 
	{
		if(a[0]>='A'&&a[0]<='Z')
		{
			char k=a[0]-'A'+'a';
			cout<<k;
		}
		else {
			char k=a[0]-'a'+'A';
			cout<<k;
		}
		for(int i=1;i<len;++i)
		{
			if(a[i]>='A'&&a[i]<='Z')
			{
				a[i]=a[i]-'A'+'a';
			}
			else if(a[i]>='a'&&a[i]<='z')
			{
				a[i]=a[i]-'a'+'A';
			}
			cout<<a[i];
		}
	}
	return 0;
}
