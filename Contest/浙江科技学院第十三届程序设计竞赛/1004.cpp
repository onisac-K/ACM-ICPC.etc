#include<bits/stdc++.h>
using namespace std;

queue<int>q;
struct s
{
	int v,d,p;
	int u;
}F[4002];

int n;

void P(int x)
{
	for(int i=x+1;i<n;++i)
	{
		if(F[i].p>=0)
		{
			F[i].p-=F[x].d;
			if(F[i].p<0)q.push(i);	
		}	
	}
}

int main()
{
	while(cin>>n)
	{
		while(!q.empty())q.pop();
		memset(F,0,sizeof(F));
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&F[i].v,&F[i].d,&F[i].p);
		}
		for(int i=0;i<n;++i)
		{
			if(F[i].p<0)continue;
			int v=F[i].v;
			for(int j=i+1;j<n&&v>0;j++)
			{
				if(F[j].p<0)
				{
					continue;
				}
				F[j].p-=v;
				v--;
				if(F[j].p<0)
				{
					F[j].u=0;
					P(j);
				}
				while(!q.empty())
				{
					int x=q.front();
					q.pop();
					P(x);
				}
			}
		}
		vector<int> v;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(F[i].p>=0)
            {
                ans++;
                v.push_back(i+1);
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<v.size();i++){
            if(i) printf(" ");
            printf("%d",v[i]);
        }
        printf("\n");
	}
}
