#include<bits/stdc++.h>
using namespace std;

int a[1005],b[1005];
int ma[1005][1005];
set<pair<int,int> >ss;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<1005;++i){
		a[i] = floor(i*1.0*(1.0+sqrt(5.0))/2);
		b[i] = a[i] + i;
		ss.insert(make_pair(a[i],b[i]));
	}
	while(t--)
	{
		int s,n,m;
		scanf("%d%d%d",&s,&n,&m);
		if(s == 1){
			if(n%2==0 || m%2==0)printf("B\n");
			else printf("G\n");
		}
		if(s == 2){
			int ans = 0;
			ans = n^m;
			if(ans == 0)printf("G\n");
			else printf("B\n");
		}
		if(s == 4){
			n--;
			m--;
			if(ss.count(make_pair(n,m)) || ss.count(make_pair(m,n))){
				cout<<"G"<<endl;
			}
			else cout<<"B"<<endl;
		}
		if(s == 3) {
            if((n+m-2) % 3 != 0) cout<<'D'<<endl;
            else {
                if(abs(n-m) == 1) cout<<'B'<<endl;
                else if(n == m) cout<<'G'<<endl;
                else cout<<'D'<<endl;
            }
        }
		
	}
} 
