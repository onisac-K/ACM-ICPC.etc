#include<bits/stdc++.h>
using namespace std;
int ans;

void ff(int x)
{
	if(x==1)return ;
	if(x%2==0)x/=2;
	else x=x*3+1;
	ans++;
	ff(x);
}


int main()
{
	int n;
	int f=1;
	while(cin>>n)
	{
		if(n==0)
		{
			printf("Case %d: %d, %d\n",f++,0,-1);
			continue;
		}
		ans = 0;
		ff(n);
		printf("Case %d: %d, %d\n",f++,n,ans);
	}
}
