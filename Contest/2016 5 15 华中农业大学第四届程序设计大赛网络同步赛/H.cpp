#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<vector>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		if(n-2*k<0)cout<<2*k-1<<endl;
		else cout<<2*k<<endl;
	}
}
