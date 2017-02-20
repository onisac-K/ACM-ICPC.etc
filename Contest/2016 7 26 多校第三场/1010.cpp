#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,v1,v2;
	while(cin>>a>>v1>>v2){
		double v = v1*v1 - v2*v2;
		v = sqrt(v);
		v1 = v; 
		double s = 1-(v2*1.0/v1)*(v2*1.0/v1);
		if(s<=0){
			cout<<"Infinity"<<endl;
			continue;
		}
		else {
			s = sqrt(s);
			double t = a*1.0/v1/s;
			printf("%.5f\n",t);
		}
	}
	return 0;
}
