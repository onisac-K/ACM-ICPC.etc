#include<bits/stdc++.h> 
using namespace std;

struct node{
	string s;
	int a,b;
	int num;
	bool operator<(const node & c)const{
		if(b!=c.b)return b>c.b;
		else return num>c.num;
	}
};

int main(){
	priority_queue<node> q;
	string s;
	int cnt =0;
	while(cin>>s){
		//cout<<s<<endl;
		if(s=="GET"){
			if(q.empty()){
				cout<<"EMPTY QUEUE!"<<endl;
				continue;
			}
			node s = q.top();
			q.pop();
			cout<<s.s<<' '<<s.a<<endl;
		}
		else {
			node s;
			cin>>s.s>>s.a>>s.b;
			s.num = cnt++;
			q.push(s);
		}
	}
}
