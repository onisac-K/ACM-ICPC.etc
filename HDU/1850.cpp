#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	int a[105];
	while(scanf("%d",&m) && m){
		int ans = 0;
		for(int i=0;i<m;++i){
			scanf("%d",&a[i]);
			ans = ans^a[i];
		}
		int num = 0;
		for(int i=0;i<m;++i){
			if(a[i]>(ans^a[i])){
				num++;
			}
		}
		printf("%d\n",num);
	}
	return 0;
 } 
