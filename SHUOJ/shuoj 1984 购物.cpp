#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
	return b==0? a:gcd(b,a%b);
}


int exgcd(int a, int b, int &x,int &y){
  	 long t,m;
  	 if ((b==0)&(a==0)) return -1;//表示无最大公因数
  	 if (b==0){
  	 	  x=1;y=0;  	 return a;
  	 } 
  	 else {
  	 	  m=exgcd(b,a%b,x,y);
   		  t=x;x=y;y=t-(a/b)*y;
   	 }
 	  return m;
} 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,m;
		cin>>a>>b>>m;
		int x,y;
		if(m%gcd(a,b)!=0)
		{
			cout<<"Impossible"<<endl;
			continue;
		}
		else 
		{
			int k=exgcd(a,b,x,y);
			int ans=x;
			int bb=y;
			while(a*x<=m)
			{
				if((m-a*x)%b==0)
				{
					ans=x;
					bb=(m-a*x)/b;
				}
				x++;
			}
		if(ans>=0&&bb>=0)cout<<ans<<' '<<bb<<endl;
		else cout<<"Impossible"<<endl;
		}
	}
	return 0;
}
