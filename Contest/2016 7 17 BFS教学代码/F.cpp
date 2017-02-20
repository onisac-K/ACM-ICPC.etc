#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N = 105;
#define F1 1
#define F2 2
#define P1 3
#define P2 4
#define DR1 5
#define DR2 6

int vis[N*N*N];
int par[N*N*N];

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	queue<int>q;
	q.push(0);
	vis[0] = -1;
	par[0] = -1;
	int cnt = 0;
	int flag = 0,ans;
	while(!q.empty()){
		int s = q.front();
		q.pop();
		int A = s/N;
		int B = s%N;
		
		if(B == c || A == c){
			ans = s;
			flag = 1;
			break;
		}
		// fill 1
		if(vis[a*N + B] == 0){
			vis[a*N + B] = F1;
			par[a*N + B] = s;
			q.push(a*N + B);
		}
		// fill 2
		if(vis[A*N + b] == 0){
			vis[A*N + b] = F2;
			par[A*N + b] = s;
			q.push(A*N + b);
		}
		// pour(1,2)
		if(vis[max(0,A-(b-B))*N+min(A+B,b)] == 0){
			vis[max(0,A-(b-B))*N+min(A+B,b)] = P1;
			par[max(0,A-(b-B))*N+min(A+B,b)] = s;
			q.push(max(0,A-(b-B))*N+min(A+B,b));
		}
		// pour(2,1)
		if(vis[min(B+A,a)*N+max(0,B-(a-A))] == 0){
			vis[min(B+A,a)*N+max(0,B-(a-A))] = P2;
			par[min(B+A,a)*N+max(0,B-(a-A))] = s;
			q.push(min(B+A,a)*N+max(0,B-(a-A)));
		}
		// drop(1)
		if(vis[B] == 0){
			vis[B] = DR1;
			par[B] = s;
			q.push(B);
		}
		// drop(2)
		if(vis[A*N] == 0){
			vis[A*N] = DR2;
			par[A*N] = s;
			q.push(A*N);
		}
	}
	if(flag == 0)cout<<"impossible"<<endl;
	else {
		vector<int> v;
		while(par[ans] != -1){
			v.push_back(vis[ans]);	
			ans = par[ans];
		}
		cout<<v.size()<<endl;
		for(int i=v.size()-1;i>=0;--i){
			if(v[i] == F1)cout<<"FILL(1)"<<endl;
			if(v[i] == F2)cout<<"FILL(2)"<<endl;
			if(v[i] == P1)cout<<"POUR(1,2)"<<endl;
			if(v[i] == P2)cout<<"POUR(2,1)"<<endl;
			if(v[i] == DR1)cout<<"DROP(1)"<<endl;
			if(v[i] == DR2)cout<<"DROP(2)"<<endl;
		}
	}
	return 0;
} 
