#include<bits/stdc++.h>
using namespace std;
int tot1[10]={128,224,768,1504,2304,4752,13088,18824,26832,39096};
int tot2[10]={51712,87152,166832,200224,256096,414072,581776,1031424,1634528,1952048};
int main()
{
	
	int n;
	int f=1;
	while(cin>>n)
	{
		printf("Case %d:\n",f++);
		if(n<=9)cout<<0<<endl;
		else if(n<20)cout<<tot1[n-10]<<endl;
		else cout<<tot2[n-20]<<endl;
		cout<<endl;
	}
	return 0;
}
