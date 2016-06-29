#include<bits/stdc++.h>
using namespace std;
int main()
{
	double s;
	int f=1;
	while(cin>>s)
	{
		double k = s;
		k/=1000;
		int cnt=0;
		while(k<8844.43)
		{

			k*=2;
			cnt++;
		}
		printf("Case %d: %.1f, %d, %.1f\n",f++,s,cnt,k);
	}
}
