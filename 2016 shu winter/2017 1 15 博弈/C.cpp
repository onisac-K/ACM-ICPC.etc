#include<bits/stdc++.h>
using namespace std;

bool ok(int n,int m)
{
	if(n%2 == 0)return 1;
	else {
		if(m%2 == 1)return 0;
		return 1;
	}
}

int main()
{
	int n,m;
	while(cin>>n>>m && (n||m)){
		if(!ok(n,m)){
			puts("What a pity!");
		}
		else puts("Wonderful!");
	}
	return 0;
}

