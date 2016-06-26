/*unfinished*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define MP make_pair
int main()
{
	ll a,b,k;
	
	while(cin>>a>>b>>k)
	{
		set<pair<ll,ll> >s;
		vector<pair<ll,ll> >v;
		s.insert(MP(a,b));
		v.PB(MP(a,b));
		ll i=0;
		for(i=0;i<k;++i)
		{
			if(a<=b)
			{
				b-=a;
				a*=2;
			}
			else 
			{
				a-=b;
				b*=2;
			}
			cout<<a<<' '<<b<<endl;
			pair<ll,ll> A=MP(a,b);
			//if(s.count(A))break;
			//else
			{
				s.insert(A);
				v.PB(MP(a,b));
			}
		}
		if(i>=k)
		{
			cout<<min(a,b)<<endl;
			continue;
		}
		k%=i;
		ll ans=min(v[k].first,v[k].second);
		cout<<ans<<endl;
		
	}
	return 0;
}
