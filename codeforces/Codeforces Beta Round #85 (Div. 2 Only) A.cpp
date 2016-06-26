#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[105];
	char b[105];
	scanf("%s%s",a,b);
	int la=strlen(a);
	int lb=strlen(b);
	for(int i=0;i<la;++i)
	{
		if(a[i]>='A'&&a[i]<='Z')a[i]=a[i]-'A'+'a';
	}
	for(int i=0;i<lb;++i)
	{
		if(b[i]>='A'&&b[i]<='Z')b[i]=b[i]-'A'+'a';
	}
	cout<<strcmp(a,b)<<endl;
	return 0;
 } 
