#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10];
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8])
	{	
		int i;	
		for(i=0;i<9;++i)
		{
			if(a[i]!=0)break;
		}
		//cout<<i<<endl;
		if(i>=9)
		{
			cout<<0<<endl;
			continue;
		}	
		if(a[i]!=1&&a[i]!=-1)cout<<a[i];
		else if(a[i]==-1)cout<<"-";
		if(9-i-1>1)cout<<"x^"<<9-i-1;
		else if(9-i-1==1)cout<<"x"<<9-i-1;
		else if(9-i-1==0)cout<<a[i];
		for(int j=i+1;j<9;++j)
		{
			if(a[j]>0)
			{
				if(a[j]==1)
				{
					if(9-j-1>1)cout<<" + x^"<<9-j-1;
					else if(9-j-1==1)cout<<" + x";
					else cout<<" + 1";
				}
				else 
				{
					cout<<" + "<<a[j];
					if(9-j-1>1)cout<<"x^"<<9-j-1;
					else if(9-j-1==1)cout<<"x";
				}
			}
			else if(a[j]<0)
			{
				if(a[j]==-1)
				{
					if(9-j-1>1)cout<<" - x^"<<9-j-1;
					else if(9-j-1==1)cout<<" - x";
					else cout<<" - 1";
				}
				else 
				{
					cout<<" - "<<-1*a[j];
					if(9-j-1>1)cout<<"x^"<<9-j-1;
					else if(9-j-1==1)cout<<"x";
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
/*0 0 0 0 0 0 0 0 1*/
