#include<iostream>
#include<queue> 
#include<vector>
using namespace std;

int G[5][5]; // ´æÍ¼ 
int vis[5][5]; // ¸¸Ç× & visit 
int dir[4][2]={1,0,0,1,-1,0,0,-1};

void init(){
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j){
			cin>>G[i][j];
			vis[i][j]=-1; 
		} 
} 

void bfs()
{
	queue<int>q;
	q.push(0);
	vis[0][0]=-2;
	while(!q.empty()){
		int S = q.front();
		q.pop();
		int x = S / 5;
		int y = S % 5;
		if(x==4 && y==4)return ;
		for(int i=0;i<4;++i){
			int tx = x + dir[i][0];
			int ty = y + dir[i][1];
			if(tx<0 || ty<0 || tx>4 || ty>4 || G[tx][ty]==1 || vis[tx][ty]!=-1)continue;
			vis[tx][ty]=S;
			q.push(tx*5+ty);
		}
	}
	return ;
}

void output(){
	vector<int> v;
	int x = 4*5+4;
	while(vis[x/5][x%5] != -2){
		v.push_back(x);
		x = vis[x/5][x%5];
	}
	cout<<"(0, 0)"<<endl;
	for(int i=v.size()-1;i>=0;--i)
		cout<<"("<<v[i]/5<<','<<' '<<v[i]%5<<")"<<endl;
}

int main(){
	init();
	bfs();
	output();
	return 0;
}
