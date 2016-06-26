#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll tree[30005];
ll a[30005];
ll ans[2000005];
ll n;

void add(ll k,ll num)  
{  
	k++;
    while(k<=30000)  
    {  
        tree[k]+=num;  
        k+=k&-k;  
    }  
}  

ll read(ll k)//1~k的区间和  
{  
    ll sum=0;
	k++;  
    while(k)  
    {  
        sum+=tree[k];  
        k-=k&-k;  
    }  
    return sum;  
}  

vector<pair<ll,ll > > v[30000]; 

int main()
{
	while(cin>>n)
	{
		memset(tree,0,sizeof(tree));
		
		int num;
		for(int i=0;i<n;++i)
			scanf("%lld",&a[i]);
		int q;
		cin>>q;
		ll u,vv;
		map<int,int> ma;
		for(int i=0;i<q;++i)v[i].clear();
		for(int i=0;i<q;++i)
		{
			scanf("%lld%lld",&u,&vv);
			u--;
			vv--;
			v[u].push_back(make_pair(vv,i));
		}
		//cout<<123<<endl;
		for(int i=0;i<=n;++i)tree[i]=0;
		for(int i=n-1;i>=0;--i)
		{
			//cout<<123<<endl;
			add(i,1);
			if(ma.count(a[i]))
			{
				add(ma[a[i]],-1);
			}
			for(int j=0;j<v[i].size();++j)
			{
				int R=v[i][j].first;
				int id = v[i][j].second;
				ans[id]=read(R);
				//cout<<id<<' '<<ans[id]<<endl;
			}
			ma[a[i]]=i;	
		}
		for(int i=0;i<q;++i)printf("%lld\n",ans[i]);
		
	}
	return 0;
} 
