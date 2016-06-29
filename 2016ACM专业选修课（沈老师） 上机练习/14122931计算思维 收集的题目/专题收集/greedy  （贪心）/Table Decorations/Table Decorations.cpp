#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*很显然，讨论一下，两种较少的气球的个数的和
是否小于最多气球的个数的一半，若小于，则每个
桌子用两个个数最多的气球，再加上另两种气球中
的任一个即可；若不小于，则最大值为三种气球的
总个数的平均数。*/

int main()
{
	ll r,g,b;
	while(cin>>r>>g>>b)
	{
		ll y = max(r,max(g,b));
		ll x = r+g+b-y; 
		if(y/2 > x)cout<<x<<endl;
		else cout<<(r+g+b)/3<<endl;
	}
	return 0;
}
