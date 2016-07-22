#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int a,b;
		int cnt = 0;
		for(int i=0;i<n;++i){
			scanf("%d%d",&a,&b);
			int k = a-b;
			if(k<0)k*=-1;
			k--;
			cnt = cnt^k; 
		}
		if(cnt>0)cout<<"I WIN!"<<endl;
		else cout<<"BAD LUCK!"<<endl;
	}
	return 0;
}
