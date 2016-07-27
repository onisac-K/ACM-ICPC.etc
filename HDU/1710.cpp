#include<bits/stdc++.h>
using namespace std;

int ans[1005];
int cnt;
int n,x[1005],z[1005];

void geth(int l1,int r1,int l2,int r2){
	//cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<' '<<x[l1]<<endl;
	ans[cnt++] = x[l1];
	if(l1 == r1 || l2 == r2)return ;
	int root;
	for(int i=l2;i<=r2;++i){
		if(z[i] == x[l1]){
			root = i;
			break;
		}
	}
	int left = root-l2;
	int right = r2-root;
	//cout<<left<<' '<<right<<endl;
	if(right>0)geth(left+l1+1,r1,root+1,r2);
	if(left>0)geth(l1+1,l1+left,l2,root-1);
}

int main() {
	while(cin>>n){
		cnt = 0;
		for(int i=1;i<=n;++i)scanf("%d",&x[i]);
		for(int i=1;i<=n;++i)scanf("%d",&z[i]);
		geth(1,n,1,n);
		for(int i=cnt-1;i>=0;--i){
			if(i>0)printf("%d ",ans[i]);
			else printf("%d\n",ans[i]);
		}
	}
	return 0;
}
