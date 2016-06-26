#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[6];
	while(cin>>a[0])
	{
		for(int i=1;i<=5;++i)cin>>a[i];
		//for(int i=0;i<6;++i)cout<<a[i]<<endl;
		int flag=0;
		for(int i=0;i<6;++i)if(a[i]!=0)flag=1;
		if(flag==0)break;
		int win=a[0]+a[2]+a[4];
		int lost=a[1]+a[3]+a[5];
		int w=0,l=0;
		for(int i=0;i<=a[0]+a[1];++i)
		{
			if(i+win==(a[0]+a[1]-i)+lost)
			{
				w=i;
				l=a[0]+a[1]-i;
				break;
			}
		}
		printf("Anna's won-loss record is %d-%d.\n",w,l);
	}
	return 0;
}
