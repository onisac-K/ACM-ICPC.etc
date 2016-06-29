#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		stack<string> s1,s2;
		string k;
		int flag = 0;
		while(cin>>k && k!="END")
		{
			if(s1.empty())
			{	
				s1.push(k);
				flag=1;
				continue;
			}
			else 
			{
				if(flag == 1)
				{
					string q = s1.top();
					if(k == q)
					{
						s2.push(k);
						flag=2;
					}
					else 
					{
						s1.push(k);
						flag=1;
					}
				}
				else 
				{
					string q = s2.top();
					if(k == q)
					{
						s1.push(k);
						flag=1;
					}
					else 
					{
						s2.push(k);
						flag=2;
					}
				}
			}
		}
		cout<<s1.size()*s2.size()<<endl;
	}
}
