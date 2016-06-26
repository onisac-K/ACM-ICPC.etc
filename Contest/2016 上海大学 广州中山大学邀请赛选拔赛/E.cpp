#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ofstream fout;
	fout.open("E.txt");
	for(int n=2;n<=20000000;++n)
	{
		ll sum=0;
		for(int i = 1; i <= n; i++) {
			sum += (int)(n/i)*i;
		}
		fout<<sum-1<<endl;
	}
	fout.close();
}

