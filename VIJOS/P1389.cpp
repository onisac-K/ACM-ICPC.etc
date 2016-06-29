#include<bits/stdc++.h>
using namespace std;

struct node
{
	string s;
	int i;
};

bool cmp(node a,node b)
{
	return a.i<b.i;
}

node a[1005];

int main()
{
	char c;
	int x;
	int i=0;
	while(scanf("%d%c",&x,&c))
	{
		a[i++].i=x;
		if(c=='\n')break;
	}
	//cout<<i<<endl;
	string b;
	for(int j=0;j<i;++j)
	{
		cin>>b;
		//cout<<b<<endl;
		a[j].s=b;
	}
	sort(a,a+i,cmp);
	for(int j=0;j<i;++j)cout<<a[j].s<<endl;
	return 0;
}
