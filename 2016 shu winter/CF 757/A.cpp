#include<bits/stdc++.h>
using namespace std;
const char pad[10] = "Bulbasr";
char str[100005];
int cnt[10];


int main()
{	
	cin>>str;
	int L = strlen(str);
	for(int i=0;i<L;++i){
		for(int j=0;j<7;++j){
			if(str[i] == pad[j]){
				cnt[j]++;
				break;
			}
		}
	}
	cnt[1]/=2;
	cnt[4]/=2;
	//for(int i=0;i<9;++i)cout<<cnt[i]<<' ';cout<<endl;
	int ans = 1000000;
	for(int i=0;i<7;++i)ans = min(ans,cnt[i]);
	cout<<ans<<endl;

	
	return 0;
 }
 
 /*
BBBBBBBBBBbbbbbbbbbbuuuuuuuuuullllllllllssssssssssaaaaaaaaaarrrrrrrrrr

 */ 
