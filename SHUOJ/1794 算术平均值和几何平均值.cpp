#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a[10];
	for(int i=0;i<5;++i)cin>>a[i];
	double sum=0;
	for(int i=0;i<5;++i)sum+=a[i];
	sum/=5;
	printf("%.2f, ",sum);
	sum=1;
	for(int i=0;i<5;++i)sum*=a[i];
	if(sum>0)
	sum=pow(sum,0.2);
	else sum=-pow(-1*sum,0.2);
	printf("%.2f",sum); 
	return 0;
}
