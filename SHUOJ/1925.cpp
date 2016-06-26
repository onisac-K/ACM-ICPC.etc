#include<bits/stdc++.h>
#include<map>
using namespace std;
int ans[100005];

int main()
{
	int t;
	scanf("%d",&t);
	int f=1;
	while(t--)
	{
		int a=0;
		int n,q;
		scanf("%d%d",&n,&q);
		printf("Case #%d:\n",f++);
		int x,r,g,b;
		set<int>s;
		map<int,int> mp;
		map<int,int> mc;
		for(int i=0;i<q;++i)
		{
			scanf("%d%d%d%d",&x,&r,&g,&b);
			int col = r*257*257+g*257+b; 
			if(!s.count(x))s.insert(x);
			if(!(mp.count(x))) {
				mp[x]=col;
				if(mc.count(col))
					mc[col]++;				
				else 
					mc[col]=1;
				
			} 
			else {
				int oldcol = mp[x];
				int ocnt = mc[oldcol];
				if(ocnt==1)mc.erase(oldcol);
				else mc[oldcol]=ocnt-1;
				mp[x]=col;
				if(mc.count(col))			
					mc[col]++;	
				else mc[col] = 1;
			}
			//cout<<"size:"<<s.size()<<endl;
			if(s.size()==n)
			{
				printf("%d\n",mc.size());
			}
			else if(mc.count(0))
			{
				printf("%d\n",mc.size());
			}
			else 
			{
				printf("%d\n",mc.size()+1);
			}
			/*cout<<"debug"<<endl;
			map<int,int> ::iterator it;
			for(it=mc.begin();it!=mc.end();it++)cout<<it->first<<" "<<it->second<<endl;
			cout<<mc.size()<<endl<<"end"<<endl;;*/
		}	
	}
	return 0;
}
/*
2
3 4
1 1 1 1
2 1 1 1
3 1 1 1
*/
