#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int i=2016;i<=990528;++i)
	{
		if((i%4==0&&i%100!=0)||i%400==0)
		{
			int x=sqrt(2*i);
			if(x*(x+1)/2==i||(x+1)*(x+2)/2==i)
			{
				int y=(x+1)/2-5;
				for(int j=y;j<x+5;++j)
				{
					if(j*(2*j-1)==i)
					{
						printf("%d\n",i);
						break;
					}
				}
			}
		}
	}
}
