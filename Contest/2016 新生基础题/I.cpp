#include<bits/stdc++.h>
using namespace std;

char a[100005];
int L ;

void change(int i)
{
	if(a[i]==' ' || i<0 || i>=L)return ;
	a[i]=' ';
	change(i+1);
	change(i-1);
}

int main()
{
	int f=1;
	while(gets(a)!=NULL)
	{
		int ans = 0;
		L =strlen(a);
		for(int i=0;i<L;++i)
		{
			if(a[i]!=' ')
			{
				ans++ ;
				change(i);
			}
		}
		printf("Case %d: ",f++);
		cout<<ans<<endl;
	}
	return 0;
}

