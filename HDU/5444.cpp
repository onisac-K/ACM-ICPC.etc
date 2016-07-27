#include<bits/stdc++.h>
using namespace std;

struct Binary{
	int l,r;
	int val;
}a[1005];

int p;

void init(int n){
	for(int i=0;i<=n;++i){
		a[i].l = a[i].r = 0; 
		a[i].val = 0;
	}
}

void insert(int x){
	int pos = 1;
	while(1){
		if(x == a[pos].val)return ;
		if(x < a[pos].val){
			if(a[pos].l == 0){
				a[pos].l = ++p;
				a[p].val = x;
				break;
			}
			else {
				pos = a[pos].l;
			}
		}
		else {
			if(a[pos].r == 0){
				a[pos].r = ++p;
				a[p].val = x;
				break;
			}
			else {
				pos = a[pos].r;
			}
		}
	}
}

void query(int x){
	int pos = 1;
	while(1){
		if(a[pos].val == x)return ;
		if(a[pos].val > x){
			printf("E");
			pos = a[pos].l;
		}
		else {
			printf("W");
			pos = a[pos].r;
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n;
		init(n);
		scanf("%d",&x);
		p = 1;
		a[1].val = x;
		for(int i=2;i<=n;++i){
			scanf("%d",&x);
			insert(x);
		}
		int q;
		cin>>q;
		while(q--){
			scanf("%d",&x);
			query(x);
			cout<<endl;
		}
	}
	return 0;
 } 
