#include<bits/stdc++.h>
using namespace std;
string a[100010];
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a,a+n);
		int lence=unique(a,a+n)-a;
		cout<<lence<<endl;
		for(int i=0;i<lence;++i)cout<<a[i]<<endl;
	}
    return 0;
} 
