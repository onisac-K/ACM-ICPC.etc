#include<bits/stdc++.h>
using namespace std;

double n;
int main()
{
	while(cin>>n){
		while(n>18)n/=18;
		if(n>9)cout<<"Ollie wins."<<endl;
		else cout<<"Stan wins."<<endl;
	}
}
//4294967294
