#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x,ans = 0;
		cin>>n;
		int flag = 0;
		for(int i=0;i<n;++i){
			cin>>x;
			ans ^= x;
			if(x>1)flag = 1; 
		}
		if((flag && ans>0) || (!flag && ans==0))cout<<"John"<<endl;
		else cout<<"Brother"<<endl;
	}
	return 0;
}
