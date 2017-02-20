#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long

struct node{
	ll g;
	ll m;
	bool operator< (const node & c)const{
		return g<c.g;
	}
}a[100005];

ll x[100005],d[100005];

int main()
{
	ll n,c,f;
	cin>>n>>c>>f;
	for(int i=0;i<c;++i){
		scanf("%I64d%I64d",&a[i].g,&a[i].m);
	}
	sort(a,a+c);
	//for(int i=0;i<c;++i)cout<<a[i].g<<endl;
	ll l = 0,r = c-1;
	int fff = 0;
	while(l<=r){
		ll mid = (l+r)>>1;
		int cnx = 0,cnd = 0;
		for(int i=0;i<mid;++i)
			x[cnx++] = a[i].m;
		for(int i=mid+1;i<c;++i)
			d[cnd++] = a[i].m;		
		int flag = 0;
		if(cnx>=n/2 && cnd>=n/2){
			ll sum = 0;
			if(n%2==1) sum += a[mid].m;
			sort(x,x+cnx);
			sort(d,d+cnd);
			for(int i=0;i<n/2;++i){
				sum += x[i];
				sum += d[i];
			}
			if(sum<=f){
				fff = 1;
				flag = 1;
			}		
		//cout<<mid<<' '<<a[mid].g<<' '<<cnx<<' '<<cnd<<' '<<sum<<endl;
		}	
		if(flag == 1){
			l = mid + 1;
		}
		else r = mid - 1;	
	}
	if(fff == 1)cout<<a[l-1].g<<endl;
	else cout<<-1<<endl;
	return 0;
 } 
 
