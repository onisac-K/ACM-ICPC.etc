#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long

struct node{
	int v;
	int c;
}a[25];

bool cmp(node a, node b)
{
	return a.v>b.v;
}

int main()
{
	int n,c;
	cin>>n>>c;
	for(int i=0;i<n;++i)scanf("%d%d",&a[i].v,&a[i].c);
	sort(a,a+n,cmp);
	//cout<<a[0].v<<' '<<a[1].v<<endl;
	int ans = 0;
	int i;
	for(i=0;i<n;++i)
		if(a[i].v>c){
			ans+=a[i].c;
			a[i].c=0;
		}
		else break;
	for(int j=i;j<n;++j){
		
		while(1)
		{
			int flag = 0;
			for(int k=j+1;k<n;++k){
				if(a[k].c == 0)continue;
				if(a[j].v + a[k].v<=c){
					flag=1;
					int kv=a[k].v,jv=a[j].v;
					int kc=a[k].c,jc=a[j].c;
					a[j].v = kv+jv;
					a[j].c = min(kc,jc);
					int q = kc-jc;
					if(q<0)q*=-1;
					a[k].c = q;
					if(kc<jc)a[k].v = jv;
				}
			}
			if(flag == 0)break;
		}		
	}
	//cout<<"debug"<<endl;
	//for(int j=i;j<n;++j)cout<<a[j].v<<' '<<a[j].c<<endl;
	for(int j=i;j<n;++j){
		if(a[j].v>=c || a[j].c==0){
			ans += a[j].c;
			continue;
		}
		for(int k=n-1;k>j;--k){
			if(a[k].c==0)continue;
			if(a[j].v+a[k].v>=c){
				int mini = min(a[j].c,a[k].c);
				ans +=mini;
				a[j].c -= mini;
				a[k].c -= mini;
			}
			if(a[j].c==0)break;
		}
		if(a[j].c>0){
			int cnt = (c+a[j].v-1)/a[j].v;
			ans += a[j].c/cnt;
		}
	}	
	cout<<ans<<endl;
	return 0;
}

/*
5 20
16 20
8 10
4 20
2 30
1 10
*/
