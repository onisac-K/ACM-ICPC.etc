#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s1[105];
	char s2[105];
	char f[2];
	int t;
	cin>>t;
	
	while(t--)
	{
		getchar();	
		gets(s1);
		gets(s2);
		//getchar();
		//cout<<s1<<endl<<s2<<endl;
		int len1=strlen(s1);
		int len2=strlen(s2);
		int i=0,j=0;
		int flag=1;
		while(i<len1||j<len2)
		{
			//cout<<i<<' '<<j<<endl;
			while(s1[i]==' ')i++;
			while(s2[j]==' ')j++;
			if(s1[i]>='A'&&s1[i]<='Z')
			{
				s1[i]=s1[i]-'A'+'a';
			}
			if(s2[j]>='A'&&s2[j]<='Z')
			{
				s2[j]=s2[j]-'A'+'a';
			}
			if(s1[i]!=s2[j])
			{
				flag=0;
				break;
			}	
			i++;
			j++;	
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 
