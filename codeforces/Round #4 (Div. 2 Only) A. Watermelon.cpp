#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int flag=0;
	for(int i=2;i<n;i+=2)
	{
		if(((n-i)&1)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
 } 
