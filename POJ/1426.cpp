#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<cstdio>

using namespace std;
#define ll long long 	
unsigned long long s;
int n;
int flag=0;
void dfs(unsigned long long i)
{
	cout<<i<<endl;
	if(i>)
	if(flag==1)return ;
	if(i%n==0)
	{
		s=i;
		flag=1;
	}
	dfs(i*10);
	dfs(i*10+1);
}

int main()
{
	
	while(cin>>n)
	{
		flag=0;
		dfs(1);
		cout<<s<<endl;
	}
	return 0;	
}
