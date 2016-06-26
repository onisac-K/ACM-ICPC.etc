#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[105];
	scanf("%s",a);
	int l=strlen(a);
	vector<int> v;
	for(int i=0;i<l;++i)
	{
		if(a[i]=='1')v.push_back(1);		
		if(a[i]=='2')v.push_back(2);		
		if(a[i]=='3')v.push_back(3);
	}
	sort(v.begin(),v.end());
	int s=v.size();
	for(int i=0;i<s-1;++i)cout<<v[i]<<'+';
	cout<<v[s-1]<<endl;
	return 0;
}
