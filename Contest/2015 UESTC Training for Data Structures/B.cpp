#include<bits/stdc++.h>
using namespace std;
const int N = 1000005 ;

struct node{
	int l;
	int r;
	int value;
}tre[(1<<21)+10];

void inser(int x)
{
	int p=1;
	for(int i=19;i>=0;--i)
	{
		if(x&(1<<i))
		{
			tre[p].r=1;
			p=p*2+1;
		}
		else 
		{
			tre[p].l=1;
			p=p*2;
		}
	}
	tre[p].value=x;
}

int findc(int x)
{
	int p=1;
	for(int i=19;i>=0;--i)
	{
		if(x&(1<<i))
		{
			if(tre[p].l)p=p*2;
			else p=p*2+1;
		}
		else 
		{
			if(tre[p].r)p=p*2+1;
			else p=p*2;
		}
	}
	return tre[p].value; 	
}


int main()
{
	int n;
	cin>>n;
	int a;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a);
		inser(a);
	}
	cin>>n;
	int b;
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&a,&b);
		if(a==0)inser(b);
		else printf("%d\n",findc(b));
	}
	return 0;
}
