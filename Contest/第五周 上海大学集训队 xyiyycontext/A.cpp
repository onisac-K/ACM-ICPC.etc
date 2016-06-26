#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define PII pair<int,int>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		int s=0;
		for(int i=0;i<4;++i)
		{
			scanf("%d",&a);
			s+=a;
		}
		if(s>=80)printf("Yes\n");
		else printf("No\n");
		
	}
	return 0;
}

